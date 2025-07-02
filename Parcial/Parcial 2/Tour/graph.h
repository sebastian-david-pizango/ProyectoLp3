#ifndef GRAPH_H
#define GRAPH_H

<<<<<<< HEAD
#include <QDialog>
#include <QMap>
#include <QVector>
#include <QListWidgetItem>
#include <QGraphicsScene>
#include <QSet>
#include <QQueue>

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

private slots:
    void on_btnAddNode_clicked();
    void on_btnDeleteNode_clicked();
    void on_btnmodifyNode_clicked();
    void on_btnAddRoute_clicked();
    void on_btnDeleteRoute_clicked();
    void on_btnModifyRoute_clicked();
    void on_btnShortestPath_clicked();

private:
    Ui::Graph *ui;
    QMap<QString, QVector<QString>> adjacencyList;
    QGraphicsScene *scene;
    QStringList selectedRoute;

    void updateNodeList();
    void updateRouteList();
    void displayResults(const QString &text);
    void bfs(const QString &startNode, QStringList &visited);
    void dfs(const QString &startNode, QStringList &visited);
    QString shortestPath(const QString &start, const QString &end);
=======
#include <QString>
#include <QList>
#include <QMap>
#include <QSet>
#include <QPair>

struct Node {
    QString name;
    double x, y;
    Node(QString name = "", double x = 0, double y = 0) : name(name), x(x), y(y) {}
};

struct Route {
    QString from;
    QString to;
    double distance;
    QString describe() const {
        return from + " -> " + to + " : " + QString::number(distance, 'f', 2) + " km";
    }
};

class Graph {
public:
    QList<Node> nodes;
    QList<Route> routes;

    void addNode(QString name, double x = 0, double y = 0);
    void removeNode(QString name);
    void editNode(QString oldName, QString newName, double x, double y);

    void addRoute(QString from, QString to, double distance);
    void removeRoute(QString from, QString to);
    void editRoute(QString from, QString to, double distance);

    QList<QString> shortestPath(QString start, QString end);
    QList<QString> dfs(QString start);
    QList<QString> bfs(QString start);

private:
    QMap<QString, QList<QPair<QString, double>>> buildAdjacencyList() const;
    void dfsHelper(QString node, QSet<QString>& visited, QList<QString>& result);
>>>>>>> 43a9f85fd96ba7ac00c22c1bd6dcaa908bbfc71d
};

#endif // GRAPH_H
