#include "mainwindow.h"
 #include <QApplication>
#include "graph.h"

#include <QMessageBox>
 43a9f85fd96ba7ac00c22c1bd6dcaa908bbfc71d

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Inicializar escena de gráficos
    scene = new QGraphicsScene(this);
    mapView = new QGraphicsView(scene, this);

    // Inicializar listas
    nodeList = new QListWidget(this);
    routeList = new QListWidget(this);

    // Inicializar botones
    btnDeleteNode = new QPushButton("Eliminar Nodo", this);
    btnDeleteRoute = new QPushButton("Eliminar Ruta", this);
    btnShortestPath = new QPushButton("Ruta más corta", this);

    // Conectar botones a sus slots
    connect(btnDeleteNode, &QPushButton::clicked, this, &MainWindow::on_btnDeleteNode_clicked);
    connect(btnDeleteRoute, &QPushButton::clicked, this, &MainWindow::on_btnDeleteRoute_clicked);
    connect(btnShortestPath, &QPushButton::clicked, this, &MainWindow::on_btnShortestPath_clicked);

    // Layouts
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(new QLabel("Nodos:"));
    leftLayout->addWidget(nodeList);
    leftLayout->addWidget(btnDeleteNode);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(new QLabel("Rutas:"));
    rightLayout->addWidget(routeList);
    rightLayout->addWidget(btnDeleteRoute);
    rightLayout->addWidget(btnShortestPath);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(mapView, 1); // que use el espacio central
    mainLayout->addLayout(rightLayout);

    QWidget *central = new QWidget(this);
    central->setLayout(mainLayout);
    setCentralWidget(central);

    // Inicializar vista
    drawGraph();
}

MainWindow::~MainWindow() {}

void MainWindow::refreshNodeList() {
    nodeList->clear();
    // ejemplo: nodeList->addItem("Nodo A");
}

void MainWindow::refreshRouteList() {
    routeList->clear();
    // ejemplo: routeList->addItem("A → B (5 km)");
}

void MainWindow::drawGraph() {
    scene->clear();
    // ejemplo: scene->addEllipse(50, 50, 10, 10);
}

void MainWindow::on_btnDeleteNode_clicked() {
    auto *item = nodeList->currentItem();
    if (!item) return;
    QString name = item->text();
    // eliminar nodo aquí
    refreshNodeList();
    drawGraph();
}

void MainWindow::on_btnDeleteRoute_clicked() {
    auto *item = routeList->currentItem();
    if (!item) return;
    QString route = item->text();
    // eliminar ruta aquí
    refreshRouteList();
    drawGraph();
}

void MainWindow::on_btnShortestPath_clicked() {
    QMessageBox::information(this, "Ruta más corta", "Aquí se mostrará el resultado.");
}
