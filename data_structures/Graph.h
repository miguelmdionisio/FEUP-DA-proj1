#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Vertex;


class Edge {
    public:
    Edge(int capacity, Vertex* dest) : capacity(capacity), dest(dest) {}

    void setCapacity(int newCapacity) { capacity = newCapacity; }
    int getCapacity() { return capacity; }

    private:
    int capacity;
    Vertex* dest;  
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


    public:

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

    int getMaxDelivery() {
        return maxDelivery;
    }

    double getDemand() {
        return demand;
    }

    int getPopulation() {
        return population;
    }
    
};

class Graph {

    vector<Vertex *> vertexSet;

    public:
        vector<Vertex *> getVertexSet() {
            return vertexSet;
        }
};