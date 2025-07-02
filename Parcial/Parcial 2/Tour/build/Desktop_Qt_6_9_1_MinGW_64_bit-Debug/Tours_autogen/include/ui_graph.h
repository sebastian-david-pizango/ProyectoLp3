/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QGraphicsView *mapView;
    QListWidget *nodeList;
    QListWidget *routeList;
    QPushButton *btnAddNode;
    QPushButton *btnDeleteNode;
    QPushButton *btnDeleteRoute;
    QPushButton *btnAddRoute;
    QPushButton *btnShortestPath;
    QPushButton *btnmodifyNode;
    QPushButton *btnModifyRoute;
    QTextEdit *results;

    void setupUi(QDialog *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName("Graph");
        Graph->resize(400, 300);
        mapView = new QGraphicsView(Graph);
        mapView->setObjectName("mapView");
        mapView->setGeometry(QRect(140, 20, 251, 201));
        nodeList = new QListWidget(Graph);
        nodeList->setObjectName("nodeList");
        nodeList->setGeometry(QRect(10, 20, 121, 131));
        routeList = new QListWidget(Graph);
        routeList->setObjectName("routeList");
        routeList->setGeometry(QRect(10, 160, 121, 131));
        btnAddNode = new QPushButton(Graph);
        btnAddNode->setObjectName("btnAddNode");
        btnAddNode->setGeometry(QRect(20, 30, 101, 29));
        btnDeleteNode = new QPushButton(Graph);
        btnDeleteNode->setObjectName("btnDeleteNode");
        btnDeleteNode->setGeometry(QRect(20, 70, 101, 29));
        btnDeleteRoute = new QPushButton(Graph);
        btnDeleteRoute->setObjectName("btnDeleteRoute");
        btnDeleteRoute->setGeometry(QRect(20, 210, 101, 29));
        btnAddRoute = new QPushButton(Graph);
        btnAddRoute->setObjectName("btnAddRoute");
        btnAddRoute->setGeometry(QRect(20, 170, 101, 29));
        btnShortestPath = new QPushButton(Graph);
        btnShortestPath->setObjectName("btnShortestPath");
        btnShortestPath->setGeometry(QRect(140, 260, 90, 29));
        btnmodifyNode = new QPushButton(Graph);
        btnmodifyNode->setObjectName("btnmodifyNode");
        btnmodifyNode->setGeometry(QRect(20, 110, 101, 29));
        btnModifyRoute = new QPushButton(Graph);
        btnModifyRoute->setObjectName("btnModifyRoute");
        btnModifyRoute->setGeometry(QRect(20, 250, 101, 29));
        results = new QTextEdit(Graph);
        results->setObjectName("results");
        results->setGeometry(QRect(240, 230, 151, 61));

        retranslateUi(Graph);

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QDialog *Graph)
    {
        Graph->setWindowTitle(QCoreApplication::translate("Graph", "Dialog", nullptr));
        btnAddNode->setText(QCoreApplication::translate("Graph", "Nuevo lugar", nullptr));
        btnDeleteNode->setText(QCoreApplication::translate("Graph", "Eliminar lugar", nullptr));
        btnDeleteRoute->setText(QCoreApplication::translate("Graph", "Eliminar ruta", nullptr));
        btnAddRoute->setText(QCoreApplication::translate("Graph", "Nueva ruta", nullptr));
        btnShortestPath->setText(QCoreApplication::translate("Graph", "Calcular", nullptr));
        btnmodifyNode->setText(QCoreApplication::translate("Graph", "Modificar lugar", nullptr));
        btnModifyRoute->setText(QCoreApplication::translate("Graph", "Modificar ruta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
