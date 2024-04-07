/**
 * @file Graph.h
 * @brief header filee for classes Vertex, Edge and Graph
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Vertex;

/**
 * @brief Edge class (pipelines)
 */
class Edge {
public:
    Edge(int capacity, Vertex* dest, Vertex* source, int flow) : capacity(capacity), dest(dest), source(source), flow(flow) {}

    Edge& operator=(const Edge& other) {
        if (this != &other) {
            capacity = other.capacity;
            dest = other.dest;
            source = other.source;
            flow = other.flow;
            aux = other.aux;
        }
        return *this;
    }

    void setCapacity(int newCapacity) { capacity = newCapacity; }
    int getCapacity() const { return capacity; }

    void setFlow(int newFlow) {
        flow = newFlow;
    }

    int getFlow() const {
        return flow;
    }

    Vertex* getDest() {
        return dest;
    }
    Vertex* getSource() {
        return source;
    }
    bool getAux() {
        return aux;
    }
    void setAux(bool visited){
        aux = visited;
    }

private:
    int capacity;
    Vertex* dest;
    Vertex* source;
    int flow;
    bool aux = false;
};

/**
 * @brief Vertex class, stores Reservoirs, Pumping Stations and Cities
 */
class Vertex {
    string type;
    int id;
    string code;

    //
    string name;
    string municipality;
    int maxDelivery;
    //
    double demand;
    int population;
    //
    bool visited;

    vector<Edge *> adj;
    Edge *path;

public:

    bool operator==(const Vertex& other) const {
        return code == other.code;
    }

    bool removeEdge(Vertex* dest){
        bool removed = false;
        auto it = adj.begin();
        while (it != adj.end()){
            auto edge = *it;
            auto edgeDest = edge->getDest();
            if (dest == edgeDest){
                it = adj.erase(it);
                delete edge;
                return true;
            }
        }
        return false;
    }

    bool operator!=(const Vertex& other) const {
        return !(*this == other);
    }

    void addEdge(Edge* edge) {
        adj.push_back(edge);
    }

    bool getVisited() const   {
        return visited;
    }

    void setVisited(bool vis)   {
        visited = vis;
    }

    Edge* getPath()  {
        return path;
    }

    void setPath(Edge* edge){
        path = edge;
    }

    void setType(string newType) {
        type = newType;
    }
    void setCode(string newCode) {
        code = newCode;
    }
    void setMunicipality(string newMunicipality) {
        municipality = newMunicipality;
    }
    void setName(string newName) {
        name = newName;
    }
    void setMaxDelivery(int newMaxDelivery) {
        maxDelivery = newMaxDelivery;
    }
    void setDemand(double newDemand) {
        demand = newDemand;
    }
    void setPopulation(int newPop){
        population = newPop;
    }

    vector<Edge *> getAdj() {
        return adj;
    }

    string getType() {
        return type;
    }

    string getCode() {
        return code;
    }

    string getMunicipality() {
        return municipality;
    }

    string getName() {
        return name;
    }

    int getMaxDelivery() const {
        return maxDelivery;
    }

    double getDemand() const {
        return demand;
    }

    int getPopulation() const {
        return population;
    }

};

/**
 * @brief Graph class, similar to the one used in class, stores vertices that store edges themselves, also has an array of edges for simplicity in given situations.
 */
class Graph {
    vector<Vertex *> vertexSet;
    vector<Edge *> edges;

public:
    /**
     * @brief removes a vertex and its edges | Complexity:
     * @param code
     */
    void removeVertex(const string& code);
    /**
     * fetches incoming edges
     * @param v
     * @return
     */
    vector<Edge *> getIncoming(Vertex* v);
    int getIncomingFlow(Vertex* v);
    void addEdge(Edge *e);
    vector<Edge *> getEdges();
    vector<Vertex *> getCities();
    vector<Vertex *> getReservoirs();
    vector<Vertex *> getStations();
    void reset();
    vector<Vertex *> getVertexSet();
    void addVertex(Vertex* vertex);
    Edge* getSibling(Edge* e);
    Edge* findEdge(Vertex* from, Vertex* to);
    void resetFlows();
    Vertex* findVertex(const string &code);
    Vertex* findvertexByName(string name);
    void checkNetworkSufficiency();
    void calculateMetrics();
    void balanceNetwork();
};

#endif // GRAPH_H
