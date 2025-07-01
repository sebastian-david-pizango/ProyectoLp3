#ifndef GRAPH_H
#define GRAPH_H

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
};

#endif // GRAPH_H
