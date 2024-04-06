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

        Edge* findEdge(Vertex* from, Vertex* to) {
        for (Edge* edge : from->getAdj()) {
            if (edge->getDest() == to) {
                return edge;
            }
        }
        return nullptr;
        }

        void resetFlows() {
        for (Edge* edge : edges) {
            edge->setFlow(0);
            }
        }

        Vertex* findVertex(const string &code) {
        for (Vertex* vertex : vertexSet) {
            if (vertex->getCode() == code) {
                return vertex;
            }
        }
        return nullptr;
        }

        bool bfs(Vertex* source, Vertex* sink, unordered_map<Vertex*, Vertex*> &parent) {
        for (Vertex* v : vertexSet) {
            v->setVisited(false);
        }
        queue<Vertex*> q;
        q.push(source);
        source->setVisited(true);
        parent[source] = nullptr; 

        while (!q.empty()) {
            Vertex* u = q.front();
            q.pop();

            for (Edge* e : u->getAdj()) {
                Vertex* v = e->getDest();
                if (!v->getVisited() && e->getFlow() < e->getCapacity()) {
                    parent[v] = u;
                    v->setVisited(true);
                    q.push(v);
                    if (v == sink) return true; 
                }
            }
        }

        return false; // No path found
        }

        int edmondsKarp(const string &sourceCode, const string &sinkCode) {
        Vertex* source = findVertex(sourceCode);
        Vertex* sink = findVertex(sinkCode);

        if (!source || !sink) {
            cerr << "Source or sink not found in the graph." << endl;
            return -1;
        }

        resetFlows(); 
        unordered_map<Vertex*, Vertex*> parent;
        int maxFlow = 0;

        while (bfs(source, sink, parent)) {
            int pathFlow = numeric_limits<int>::max();

            for (Vertex* v = sink; v != source; v = parent[v]) {
                Vertex* u = parent[v];
                Edge* e = findEdge(u, v);
                pathFlow = min(pathFlow, e->getCapacity() - e->getFlow());
            }

            
            for (Vertex* v = sink; v != source; v = parent[v]) {
                Vertex* u = parent[v];
                Edge* forwardEdge = findEdge(u, v);
                Edge* reverseEdge = findEdge(v, u); 

                forwardEdge->setFlow(forwardEdge->getFlow() + pathFlow);
                if (reverseEdge) {
                    reverseEdge->setFlow(reverseEdge->getFlow() - pathFlow); // Reverse the flow
                } else {
                    reverseEdge = new Edge(0, u, v); 
                    reverseEdge->setFlow(-pathFlow); 
                    v->addEdge(reverseEdge);
                }
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
        }

        void calculateMaxFlowToCity(const string& cityCode) {
        ofstream outputFile("max_flow_results.txt");
        for (Vertex* reservoir : getReservoirs()) {
            int maxFlow = edmondsKarp(reservoir->getCode(), cityCode);
            cout << "(" << reservoir->getCode() << " -> " << cityCode << ", " << maxFlow << ")" << endl;
            outputFile << "(" << reservoir->getCode() << " -> " << cityCode << ", " << maxFlow << ")" << endl;
        }
        outputFile.close();
        }

        void calculateMaxFlowToAllCities() {
        ofstream outputFile("max_flow_results.txt");
        for (Vertex* city : getCities()) {
            for (Vertex* reservoir : getReservoirs()) {
                int maxFlow = edmondsKarp(reservoir->getCode(), city->getCode());
                cout << "(" << reservoir->getCode() << " -> " << city->getCode() << ", " << maxFlow << ")" << endl;
                outputFile << "(" << reservoir->getCode() << " -> " << city->getCode() << ", " << maxFlow << ")" << endl;
            }
        }
        outputFile.close();
        }

        vector<Edge*> getIncoming(Vertex* v) {
        vector<Edge*> incoming;
        for (auto& edge : edges) {
            if (edge->getDest() == v) {
                incoming.push_back(edge);
            }
        }
        return incoming;
        }

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

        void calculateMetrics() {
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

        double calculateAverage(const vector<double>& differences) {
        double sum = accumulate(differences.begin(), differences.end(), 0.0);
        return sum / differences.size();
        }

        double calculateVariance(const vector<double>& differences, double average) {
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


};