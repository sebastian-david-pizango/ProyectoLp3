#include "graph.h"
#include "ui_graph.h"
#include <QInputDialog>
#include <QMessageBox>

Graph::Graph(QWidget *parent)
    : QDialog(parent), ui(new Ui::Graph)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->mapView->setScene(scene);

    // Conectar botones
    connect(ui->btnAddNode, &QPushButton::clicked, this, &Graph::on_btnAddNode_clicked);
    connect(ui->btnDeleteNode, &QPushButton::clicked, this, &Graph::on_btnDeleteNode_clicked);
    connect(ui->btnmodifyNode, &QPushButton::clicked, this, &Graph::on_btnmodifyNode_clicked);
    connect(ui->btnAddRoute, &QPushButton::clicked, this, &Graph::on_btnAddRoute_clicked);
    connect(ui->btnDeleteRoute, &QPushButton::clicked, this, &Graph::on_btnDeleteRoute_clicked);
    connect(ui->btnModifyRoute, &QPushButton::clicked, this, &Graph::on_btnModifyRoute_clicked);
    connect(ui->btnShortestPath, &QPushButton::clicked, this, &Graph::on_btnShortestPath_clicked);
}

Graph::~Graph()
{
    delete ui;
}

void Graph::on_btnAddNode_clicked()
{
    bool ok;
    QString node = QInputDialog::getText(this, "Nuevo lugar", "Nombre del lugar:", QLineEdit::Normal, "", &ok);
    if (ok && !node.isEmpty() && !adjacencyList.contains(node)) {
        adjacencyList[node] = {};
        updateNodeList();
    }
}

void Graph::on_btnDeleteNode_clicked()
{
    QListWidgetItem *item = ui->nodeList->currentItem();
    if (item) {
        QString node = item->text();
        adjacencyList.remove(node);
        for (auto &neighbors : adjacencyList) {
            neighbors.removeAll(node);
        }
        updateNodeList();
        updateRouteList();
    }
}

void Graph::on_btnmodifyNode_clicked()
{
    QListWidgetItem *item = ui->nodeList->currentItem();
    if (item) {
        QString node = item->text();
        bool ok;
        QString newNode = QInputDialog::getText(this, "Modificar lugar", "Nuevo nombre:", QLineEdit::Normal, node, &ok);
        if (ok && !newNode.isEmpty() && newNode != node) {
            QVector<QString> edges = adjacencyList[node];
            adjacencyList.remove(node);
            adjacencyList[newNode] = edges;
            for (auto &neighbors : adjacencyList) {
                for (int i = 0; i < neighbors.size(); ++i) {
                    if (neighbors[i] == node)
                        neighbors[i] = newNode;
                }
            }
            updateNodeList();
            updateRouteList();
        }
    }
}

void Graph::on_btnAddRoute_clicked()
{
    auto items = ui->nodeList->selectedItems();
    if (items.size() >= 2) {
        for (int i = 0; i < items.size() - 1; ++i) {
            QString from = items[i]->text();
            QString to = items[i+1]->text();
            if (!adjacencyList[from].contains(to))
                adjacencyList[from].append(to);
            if (!adjacencyList[to].contains(from))
                adjacencyList[to].append(from);
        }
        selectedRoute.clear();
        for (QListWidgetItem *item : items)
            selectedRoute.append(item->text());
        updateRouteList();
    }
}

void Graph::on_btnDeleteRoute_clicked()
{
    for (int i = 0; i < selectedRoute.size() - 1; ++i) {
        QString from = selectedRoute[i];
        QString to = selectedRoute[i+1];
        adjacencyList[from].removeAll(to);
        adjacencyList[to].removeAll(from);
    }
    selectedRoute.clear();
    updateRouteList();
}

void Graph::on_btnModifyRoute_clicked()
{
    auto items = ui->nodeList->selectedItems();
    selectedRoute.clear();
    for (QListWidgetItem *item : items)
        selectedRoute.append(item->text());
    updateRouteList();
}

void Graph::on_btnShortestPath_clicked()
{
    if (selectedRoute.size() < 2)
        return;

    QString start = selectedRoute.first();
    QString end = selectedRoute.last();
    QStringList dfsResult, bfsResult;
    dfs(start, dfsResult);
    bfs(start, bfsResult);

    QString result;
    result += "Ruta mínima: " + shortestPath(start, end) + "\n";
    result += "Recorrido DFS: " + dfsResult.join(" -> ") + "\n";
    result += "Recorrido BFS: " + bfsResult.join(" -> ");

    displayResults(result);
}

void Graph::dfs(const QString &startNode, QStringList &visited)
{
    QSet<QString> visitedSet;
    std::function<void(QString)> dfsRec = [&](QString node) {
        if (visitedSet.contains(node)) return;
        visitedSet.insert(node);
        visited.append(node);
        for (const QString &neighbor : adjacencyList[node])
            dfsRec(neighbor);
    };
    dfsRec(startNode);
}

void Graph::bfs(const QString &startNode, QStringList &visited)
{
    QSet<QString> visitedSet;
    QQueue<QString> queue;
    queue.enqueue(startNode);
    visitedSet.insert(startNode);

    while (!queue.isEmpty()) {
        QString current = queue.dequeue();
        visited.append(current);
        for (const QString &neighbor : adjacencyList[current]) {
            if (!visitedSet.contains(neighbor)) {
                visitedSet.insert(neighbor);
                queue.enqueue(neighbor);
            }
        }
    }
}

QString Graph::shortestPath(const QString &start, const QString &end)
{
    QMap<QString, QString> previous;
    QQueue<QString> queue;
    QSet<QString> visited;
    queue.enqueue(start);
    visited.insert(start);

    while (!queue.isEmpty()) {
        QString current = queue.dequeue();
        if (current == end) break;
        for (const QString &neighbor : adjacencyList[current]) {
            if (!visited.contains(neighbor)) {
                visited.insert(neighbor);
                previous[neighbor] = current;
                queue.enqueue(neighbor);
            }
        }
    }

    if (!previous.contains(end)) return "No hay ruta";

    QStringList path;
    QString step = end;
    while (step != start) {
        path.prepend(step);
        step = previous[step];
    }
    path.prepend(start);
    return path.join(" -> ");
}

void Graph::updateNodeList()
{
    ui->nodeList->clear();
    for (const QString &node : adjacencyList.keys())
        ui->nodeList->addItem(node);
}

void Graph::updateRouteList()
{
    ui->routeList->clear();
    for (const QString &node : selectedRoute)
        ui->routeList->addItem(node);
}

void Graph::displayResults(const QString &text)
{
    ui->results->setText(text);
}
