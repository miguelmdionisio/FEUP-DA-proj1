#include "Graph.h"


void Graph::removeVertex(const string& code) {
    Vertex* vertexToRemove = nullptr;

    for (auto it = vertexSet.begin(); it != vertexSet.end(); ++it) {
        if ((*it)->getCode() == code) {
            vertexToRemove = *it;
            vertexSet.erase(it);
            break;
        }
    }

    if (vertexToRemove) {
        for (auto it = edges.begin(); it != edges.end(); ) {
            if ((*it)->getSource() == vertexToRemove || (*it)->getDest() == vertexToRemove) {
                delete *it;
                it = edges.erase(it);
            } else {
                ++it;
            }
        }
    }
}

vector<Edge *> Graph::getIncoming(Vertex* v){
    vector<Edge *> incoming;
    for (auto e: edges){
        if (e->getDest() == v){
            incoming.push_back(e);
        }
    }
    return incoming;
}

int Graph::getIncomingFlow(Vertex* v){
    auto incoming = getIncoming(v);
    int flow = 0;
    for (auto e: incoming)  {
        flow += e->getFlow();
    }
    return flow;
}

void Graph::addEdge(Edge *e){
    edges.push_back(e);
}

vector<Edge *> Graph::getEdges()   {
    return edges;
}

vector<Vertex *> Graph::getCities() {
    vector<Vertex *> cities;
    for (auto v : vertexSet) {
        if (v->getType() == "city") {
            cities.push_back(v);
        }
    }
    return cities;
}

vector<Vertex *> Graph::getReservoirs() {
    vector<Vertex *> reservoirs;
    for (auto v : vertexSet) {
        if (v->getType() == "reservoir") {
            reservoirs.push_back(v);
        }
    }
    return reservoirs;
}

vector<Vertex *> Graph::getStations() {
    vector<Vertex *> stations;
    for (auto v : vertexSet) {
        if (v->getType() == "station") {
            stations.push_back(v);
        }
    }
    return stations;
}

void Graph::reset() {
    for (auto v : vertexSet) {
        v->setVisited(false);
    }
}

vector<Vertex *> Graph::getVertexSet() {
    return vertexSet;
}

void Graph::addVertex(Vertex* vertex) {
    vertexSet.push_back(vertex);
}

Edge* Graph::getSibling(Edge* e){
    return findEdge(e->getDest(), e->getSource());
}

Edge* Graph::findEdge(Vertex* from, Vertex* to) {
    for (Edge* edge : from->getAdj()) {
        if (edge->getDest() == to) {
            return edge;
        }
    }
    return nullptr;
}

void Graph::resetFlows() {
    for (Edge* edge : edges) {
        edge->setFlow(0);
    }
}

Vertex* Graph::findVertex(const string &code) {
    for (Vertex* vertex : vertexSet) {
        if (vertex->getCode() == code) {
            return vertex;
        }
    }
    return nullptr;
}

Vertex* Graph::findvertexByName(string name) {
    for (Vertex* vertex : vertexSet) {
        if (vertex->getName() == name) {
            return vertex;
        }
    }
    return nullptr;
}
/*

void Graph::checkNetworkSufficiency() {
    bool allNeedsMet = true;

    for (Vertex* city : getCities()) {
        double totalSupply = 0;

        for (Edge* edge : getIncoming(city)) {
            totalSupply += edge->getFlow(); 
        }

        double demand = city->getDemand();
        if (totalSupply < demand) {
            allNeedsMet = false;
            double deficit = demand - totalSupply;
            cout << "City in deficit: " << city->getCode() << ", Deficit: " << deficit << endl;
        }
    }

    if (allNeedsMet) {
        cout << "All cities' water needs are met by the current network configuration." << endl;
    }
}

void Graph::calculateMetrics() {
    vector<double> differences;
    for (auto& edge : edges) {
        double difference = edge->getCapacity() - edge->getFlow();
        differences.push_back(difference);
    }

    double averageDifference = calculateAverage(differences);
    double variance = calculateVariance(differences, averageDifference);
    double maxDifference = *max_element(differences.begin(), differences.end());

    cout << "Average Difference: " << averageDifference << endl;
    cout << "Variance: " << variance << endl;
    cout << "Maximum Difference: " << maxDifference << endl;
}

double Graph::calculateAverage(const vector<double>& differences) {
    double sum = accumulate(differences.begin(), differences.end(), 0.0);
    return sum / differences.size();
}

double Graph::calculateVariance(const vector<double>& differences, double average) {
    double variance = 0.0;
    for (double diff : differences) {
        variance += pow(diff - average, 2);
    }
    return variance / differences.size();
}

void Graph::balanceNetwork() {
    double totalExcessCapacity = 0;
    double totalUnmetDemand = 0;

    for (Vertex* city : getCities()) {
        double incomingFlow = 0;
        for (Edge* edge : getIncoming(city)) {
            incomingFlow += edge->getFlow();
        }
        double unmetDemand = city->getDemand() - incomingFlow;
        if (unmetDemand > 0) {
            totalUnmetDemand += unmetDemand;
        }
    }

    for (Edge* edge : edges) {
        double excessCapacity = edge->getCapacity() - edge->getFlow();
        if (excessCapacity > 0) {
            totalExcessCapacity += excessCapacity;
        }
    }

    if (totalUnmetDemand <= 0 || totalExcessCapacity <= 0) {
        return;
    }

    for (Edge* edge : edges) {
        double excessCapacity = edge->getCapacity() - edge->getFlow();
        if (excessCapacity > 0) {
            double flowIncrease = (excessCapacity / totalExcessCapacity) * totalUnmetDemand;
            edge->setFlow(edge->getFlow() + min(flowIncrease, excessCapacity));
        }
    }
    }
    */

