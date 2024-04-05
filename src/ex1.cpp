#include <queue>
#include <xmath.h>
#include "ex1.h"
#include "../data_structures/Graph.h"

using namespace std;

void edmondsKarp(Graph *g, Vertex* source, Vertex* target) {
    if (source == nullptr || target == nullptr || source == target)
        throw std::logic_error("Invalid source and/or target vertex");

    for (auto v : g->getVertexSet()) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }

    while( findAugmentingPath(g, source, target) ) {
        double f = findMinResidualAlongPath(source, target);
        augmentFlowAlongPath(source, target, f);
    }
}


void testAndVisit(std::queue<Vertex*> &q, Edge *e, Vertex *w, double residual) {

    if (! w->getVisited() && residual > 0) {

        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}


bool findAugmentingPath(Graph *g, Vertex *s, Vertex *t) {

    for(auto v : g->getVertexSet()) {
        v->setVisited(false);
    }

    s->setVisited(true);
    std::queue<Vertex *> q;
    q.push(s);

    while( ! q.empty() && !t->getVisited()) {
        auto v = q.front();
        q.pop();

        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getCapacity() - e->getFlow());
        }
// Process incoming edges
        for(auto e: g->getIncoming(v)) {
            testAndVisit(q, e, e->getSource(), e->getFlow());
        }
    }
// Return true if a path to the target is found, false otherwise
    return t->getVisited();
}

double findMinResidualAlongPath(Vertex *s, Vertex *t) {
    int f = INF;
// Traverse the augmenting path to find the minimum residual capacity
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getCapacity() - e->getFlow());
            v = e->getSource();
        }
        else {
            f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
// Return the minimum residual capacity
    return f;
}


void augmentFlowAlongPath(Vertex *s, Vertex *t, double f) {
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getSource();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}
