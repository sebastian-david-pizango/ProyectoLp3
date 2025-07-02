#ifndef GRAPH_H
#define GRAPH_H

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
};

#endif // GRAPH_H
