#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerwindow.h"
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->mapView->setScene(scene);
    refreshNodeList();
    refreshRouteList();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::refreshNodeList() {
    ui->nodeList->clear();
    for (const auto& n : graph.nodes)
        ui->nodeList->addItem(n.name);
}

void MainWindow::refreshRouteList() {
    ui->routeList->clear();
    for (const auto& r : graph.routes)
        ui->routeList->addItem(r.describe());
}

void MainWindow::drawGraph() {
    scene->clear();
    for (const auto& r : graph.routes) {
        Node* from = nullptr;
        Node* to = nullptr;
        for (auto& n : graph.nodes) {
            if (n.name == r.from) from = &n;
            if (n.name == r.to) to = &n;
        }
        if (from && to) {
            scene->addLine(from->x, from->y, to->x, to->y);
            scene->addText(QString::number(r.distance) + " km")
                ->setPos((from->x + to->x) / 2, (from->y + to->y) / 2);
        }
    }
    for (const auto& n : graph.nodes) {
        scene->addEllipse(n.x - 5, n.y - 5, 10, 10);
        scene->addText(n.name)->setPos(n.x + 10, n.y);
    }
}

void MainWindow::on_btnAddNode_clicked() {
    QString name = QInputDialog::getText(this, "Nuevo nodo", "Nombre:");
    if (name.isEmpty()) return;
    double x = QInputDialog::getDouble(this, "Coordenada X", "X:", 100, 0, 1000);
    double y = QInputDialog::getDouble(this, "Coordenada Y", "Y:", 100, 0, 1000);
    graph.addNode(name, x, y);
    refreshNodeList();
    drawGraph();
}

<<<<<<< HEAD
void MainWindow::on_btnDeleteNode_clicked() {
    QString name = ui->nodeList->currentItem()->text();
    graph.removeNode(name);
    refreshNodeList();
    refreshRouteList();
    drawGraph();
}

void MainWindow::on_btnAddRoute_clicked() {
    QString from = QInputDialog::getText(this, "Desde", "Nodo origen:");
    QString to = QInputDialog::getText(this, "Hasta", "Nodo destino:");
    double distance = QInputDialog::getDouble(this, "Distancia", "En km:", 1, 0.1, 1000);
    graph.addRoute(from, to, distance);
    refreshRouteList();
    drawGraph();
}

void MainWindow::on_btnDeleteRoute_clicked() {
    QString route = ui->routeList->currentItem()->text();
    QStringList parts = route.split(" ");
    if (parts.size() >= 3)
        graph.removeRoute(parts[0], parts[2]);
    refreshRouteList();
    drawGraph();
}

void MainWindow::on_btnShortestPath_clicked() {
    QString start = QInputDialog::getText(this, "Inicio", "Nodo inicial:");
    QString end = QInputDialog::getText(this, "Fin", "Nodo final:");
    auto path = graph.shortestPath(start, end);
    QMessage
=======

>>>>>>> 4d4cc450ad9e926ecda62c2d71504fbe9cf317be
