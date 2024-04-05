#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Vertex;


class Edge {
    public:
    Edge(int capacity, Vertex* dest, Vertex* source) : capacity(capacity), dest(dest), source(source) {}

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

    private:
    int capacity;
    Vertex* dest;
    Vertex* source;
    int flow;
};


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

    void removeEdge(Vertex* dest) {
        for (auto it = adj.begin(); it != adj.end(); ++it) {
            if ((*it)->getDest() == dest) {
                adj.erase(it);
                break;
            }
        }
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

class Graph {

    vector<Vertex *> vertexSet;
    vector<Edge *> edges;

    public:

        vector<Edge *> getIncoming(Vertex* v){
            vector<Edge *> incoming;
            for (auto e: edges){
                if (e->getSource() == v){
                    incoming.push_back(e);
                }
            }
            return incoming;
        }

        void addEdge(Edge *e){
            edges.push_back(e);
        }

        vector<Edge *> getEdges()   {
            return edges;
        }

        vector<Vertex *> getCities() {
            vector<Vertex *> cities;
            for (auto v : vertexSet) {
                if (v->getType() == "city") {
                    cities.push_back(v);
                }
            }
            return cities;
        }

        vector<Vertex *> getReservoirs() {
            vector<Vertex *> reservoirs;
            for (auto v : vertexSet) {
                if (v->getType() == "reservoir") {
                    reservoirs.push_back(v);
                }
            }
            return reservoirs;
        }

        vector<Vertex *> getStations() {
            vector<Vertex *> stations;
            for (auto v : vertexSet) {
                if (v->getType() == "station") {
                    stations.push_back(v);
                }
            }
            return stations;
        }

        void reset() {
            for (auto v : vertexSet) {
                v->setVisited(false);
            }
        }

        vector<Vertex *> getVertexSet() {
            return vertexSet;
        }

        void addVertex(Vertex* vertex) {
            vertexSet.push_back(vertex);
        }   
};