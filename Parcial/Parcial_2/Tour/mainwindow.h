#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnDeleteNode_clicked();
    void on_btnDeleteRoute_clicked();
    void on_btnShortestPath_clicked();

private:
    void refreshNodeList();
    void refreshRouteList();
    void drawGraph();

    QGraphicsView *mapView;
    QGraphicsScene *scene;
    QListWidget *nodeList;
    QListWidget *routeList;
    QPushButton *btnDeleteNode;
    QPushButton *btnDeleteRoute;
    QPushButton *btnShortestPath;
};

#endif // MAINWINDOW_H


