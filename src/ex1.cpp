#include <queue>
#include <xmath.h>
#include <fstream>
#include "ex1.h"
#include "../data_structures/Graph.h"

using namespace std;


void printDeficits(Graph* originalGraph){

    Graph* g = new Graph(*originalGraph);
    
    auto reservoirs = g->getReservoirs();
    auto cities = g->getCities();

    auto *superSource = new Vertex();
    auto *superSink = new Vertex();
    superSource->setCode("SSource");
    superSink->setCode("SSink");
    g->addVertex(superSource);
    g->addVertex(superSink);

    for (auto reservoir: reservoirs) {
        auto e = new Edge(reservoir->getMaxDelivery(), reservoir, superSource, 0);
        superSource->addEdge(e);
        g->addEdge(e);
    }
    for (auto city: cities) {
        auto e = new Edge(city->getDemand(), superSink, city, 0);
        city->addEdge(e);
        g->addEdge(e);
    }
    edmondsKarp(g, superSource, superSink);

    for(auto city: cities){
        for (auto e: g->getIncoming(city)){
            if (e->getFlow() < city->getDemand()){
                cout << city->getName() << ":" << endl;
                cout << "Demand: " << city->getDemand() << endl;
                cout << "Actual Flow: " << e->getFlow() << endl;
                cout << "Deficit: " << city->getDemand() - e->getFlow() << endl;
            }
        }
    }
}

void calculateMaxFlowToCities(Graph* originalGraph, Vertex* vertex) {

    Graph* g = new Graph(*originalGraph);

    std::ofstream outputFile("output.txt");

    auto reservoirs = g->getReservoirs();
    auto cities = g->getCities();

    auto *superSource = new Vertex();
    auto *superSink = new Vertex();
    superSource->setCode("SSource");
    superSink->setCode("SSink");
    g->addVertex(superSource);
    g->addVertex(superSink);

    for (auto reservoir: reservoirs) {
        auto e = new Edge(reservoir->getMaxDelivery(), reservoir, superSource, 0);
        superSource->addEdge(e);
        g->addEdge(e);
    }
    for (auto city: cities) {
        auto e = new Edge(city->getDemand(), superSink, city, 0);
        city->addEdge(e);
        g->addEdge(e);
    }


    edmondsKarp(g, superSource, superSink);


    if (vertex == nullptr){
        for (auto city: cities) {
            for (auto e: g->getIncoming(city)) {
                outputFile << city->getName() << " - " << e->getFlow() << endl;
                cout << city->getName() << " - " << e->getFlow() << endl;
            }
        }
        outputFile.close();
    } else{
        for (auto e: g->getIncoming(vertex)) cout << vertex->getName() << " - " << e->getFlow() << endl;
    }
}

void edmondsKarp(Graph *g, Vertex* source, Vertex* target) {
    if (source == nullptr || target == nullptr || source == target)
        throw std::logic_error("Invalid source or target vertex");

    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }


    while(findAugmentingPath(g, source, target) ) {
        double f = findMinResidualAlongPath(source, target);
        augmentFlowAlongPath(source, target, f);
    }
}


void testAndVisit(std::queue<Vertex*> &q, Edge *e, Vertex *w, double residual) {
    if (!w->getVisited() && residual > 0) {
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

    while(!q.empty() && !t->getVisited()) {
        auto v = q.front();
        q.pop();

        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getCapacity() - e->getFlow());
        }

        for(auto e: g->getIncoming(v)) {
            testAndVisit(q, e, e->getSource(), e->getFlow());
        }
    }
    return t->getVisited();
}

double findMinResidualAlongPath(Vertex *s, Vertex *t) {
    int f = INF;
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