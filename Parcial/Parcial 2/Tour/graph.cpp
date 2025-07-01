#include "graph.h"
#include <QQueue>
#include <limits>
#include <algorithm>

void Graph::addNode(QString name, double x, double y) {
    nodes.append(Node(name, x, y));
}

void Graph::removeNode(QString name) {
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(),
                               [&](const Node& n){ return n.name == name; }), nodes.end());
    routes.erase(std::remove_if(routes.begin(), routes.end(),
                                [&](const Route& r){ return r.from == name || r.to == name; }), routes.end());
}

void Graph::editNode(QString oldName, QString newName, double x, double y) {
    for (Node& n : nodes) {
        if (n.name == oldName) {
            n.name = newName;
            n.x = x;
            n.y = y;
            break;
        }
    }
    for (Route& r : routes) {
        if (r.from == oldName) r.from = newName;
        if (r.to == oldName) r.to = newName;
    }
}

void Graph::addRoute(QString from, QString to, double distance) {
    routes.append(Route{from, to, distance});
}

void Graph::removeRoute(QString from, QString to) {
    routes.erase(std::remove_if(routes.begin(), routes.end(),
                                [&](const Route& r){ return (r.from == from && r.to == to) || (r.from == to && r.to == from); }), routes.end());
}

void Graph::editRoute(QString from, QString to, double distance) {
    for (Route& r : routes) {
        if ((r.from == from && r.to == to) || (r.from == to && r.to == from)) {
            r.distance = distance;
            break;
        }
    }
}

QMap<QString, QList<QPair<QString, double>>> Graph::buildAdjacencyList() const {
    QMap<QString, QList<QPair<QString, double>>> adj;
    for (const Route& r : routes) {
        adj[r.from].append({r.to, r.distance});
        adj[r.to].append({r.from, r.distance});
    }
    return adj;
}

QList<QString> Graph::shortestPath(QString start, QString end) {
    auto adj = buildAdjacencyList();
    QMap<QString, double> dist;
    QMap<QString, QString> prev;
    QSet<QString> visited;
    for (const Node& n : nodes) dist[n.name] = std::numeric_limits<double>::infinity();
    dist[start] = 0;
    while (visited.size() < nodes.size()) {
        QString minNode;
        double minDist = std::numeric_limits<double>::infinity();
        for (auto it = dist.constBegin(); it != dist.constEnd(); ++it) {
            if (!visited.contains(it.key()) && it.value() < minDist) {
                minDist = it.value();
                minNode = it.key();
            }
        }
        if (minNode.isEmpty()) break;
        visited.insert(minNode);
        for (auto& pkg : adj[minNode]) {
            const QString& neighbor = pkg.first;
            double cost = pkg.second;
            if (visited.contains(neighbor)) continue;
            double alt = dist[minNode] + cost;
            if (alt < dist[neighbor]) {
                dist[neighbor] = alt;
                prev[neighbor] = minNode;
            }
        }
    }
    QList<QString> path;
    for (QString at = end; !at.isEmpty(); at = prev.value(at)) {
        path.prepend(at);
    }
    if (path.isEmpty() || path.first() != start) return {};
    return path;
}

void Graph::dfsHelper(QString node, QSet<QString>& visited, QList<QString>& result) {
    visited.insert(node);
    result.append(node);
    for (auto& pkg : buildAdjacencyList()[node]) {
        QString n2 = pkg.first;
        if (!visited.contains(n2)) dfsHelper(n2, visited, result);
    }
}

QList<QString> Graph::dfs(QString start) {
    QSet<QString> visited;
    QList<QString> result;
    dfsHelper(start, visited, result);
    return result;
}

QList<QString> Graph::bfs(QString start) {
    QSet<QString> visited;
    QQueue<QString> queue;
    QList<QString> result;
    visited.insert(start);
    queue.enqueue(start);
    auto adj = buildAdjacencyList();
    while (!queue.isEmpty()) {
        QString current = queue.dequeue();
        result.append(current);
        for (auto& pkg : adj[current]) {
            QString n2 = pkg.first;
            if (!visited.contains(n2)) {
                visited.insert(n2);
                queue.enqueue(n2);
            }
        }
    }
    return result;
}
