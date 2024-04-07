#include "ex3.h"
#include "ex1.h"


void removeReservoir(Graph* g, string res){

    string name = g->findVertex(res)->getName();
    g->removeVertex(res);

    calculateMaxFlowToCities(g);

    auto cities = g->getCities();

    cout << "Cities that do not meet demand with reservoir " << name << " removed:" << endl;
    for (auto city: cities){
        for (auto e: city->getAdj()){
            if (e->getFlow()<city->getDemand()){
                cout << city->getName() << ": Demand - " << city->getDemand() << " | Actual flow - " << e->getFlow()<< endl;
            }
        }
    }
}

void simulatePipelineFailure(Graph* g) {

    auto cities = g->getCities();

    auto edges = g->getEdges();

    // TESTE
    /*
    auto novedez = g->findEdge(g->findVertex("PS_9"), g->findVertex("PS_10"));
    auto quatrocinco = g->findEdge(g->findVertex("PS_4"), g->findVertex("PS_5"));
    auto sibling9 = g->getSibling(novedez);
    auto sibling4 = g->getSibling(quatrocinco);
    if (sibling9 != nullptr) sibling9->setCapacity(0);
    if (sibling4 != nullptr) sibling4->setCapacity(0);

    auto cap9 = novedez->getCapacity();
    auto cap4 = quatrocinco->getCapacity();

    novedez->setCapacity(0);
    quatrocinco->setCapacity(0);

    calculateMaxFlowToCities(g);

    for (auto city: g->getCities()){
        cout << city->getName() << ": " << g->getIncomingFlow(city) << endl;
    }

    novedez->setCapacity(cap9);
    quatrocinco->setCapacity(cap4);
    if (sibling9 != nullptr) sibling9->setCapacity(cap9);
    if (sibling4 != nullptr) sibling4->setCapacity(cap4);
    */
    //FIMDETESTE


    for (auto& edge : edges) {
        if (edge->getAux()) continue;

        auto sibling = g->getSibling(edge);
        if (sibling != nullptr) {
            sibling->setCapacity(0);
            sibling->setAux(true);
            edge->setAux(true);
        }
        double capacity = edge->getCapacity();

        edge->setCapacity(0);
        calculateMaxFlowToCities(g);

        for (auto city: g->getCities()){
            auto simFlow = g->getIncomingFlow(city);
            if (simFlow < city->getDemand()){
                cout <<city->getName()<< " in rupture of pipe " << edge->getSource()->getCode() << " to " << edge->getDest()->getCode() << " deficit of " << city->getDemand()-simFlow << endl;
            }
        }

        edge->setCapacity(capacity);
        if (sibling != nullptr) sibling->setCapacity((capacity));
    }
}

void takeOutStation(Graph* g, string station){
    
}

struct EdgeData {
    int capacity;
    std::string destCode;
    std::string sourceCode;
    int flow;
};

void removePumpingStations(Graph* g) {
    auto originalStations = g->getStations();

    // Iterating over the stations to check the impact of their removal.
    for (auto& station : originalStations) {
        string name = station->getName();
        string code = station->getCode();

        // Save the edges to restore them later.
        vector<EdgeData> edgesData;
        for (auto edge : station->getAdj()) {
            edgesData.push_back(EdgeData{edge->getCapacity(), edge->getDest()->getCode(), edge->getSource()->getCode(), edge->getFlow()});
        }

        // Remove the station temporarily.
        g->removeVertex(code);

        // Recalculate max flow after removing the station.
        calculateMaxFlowToCities(g);

        vector<Vertex*> cities = g->getCities();
        bool allDemandsMet = true;
        cout << "Affected cities when pumping station " << name << " (" << code << ") is removed:" << endl;

        // Check each city for any water supply deficit.
        for (auto city : cities) {
            if (g->getIncomingFlow(city) < city->getDemand()) {
                allDemandsMet = false;
                cout << "City Code: " << city->getCode() << " | Water Supply Deficit: " << city->getDemand() - g->getIncomingFlow(city) << endl;
            }
        }

        if (allDemandsMet) {
            cout << "No cities are affected when pumping station " << name << " (" << code << ") is temporarily removed." << endl;
        }

        // Restore the station with its original edges.
        auto newStation = new Vertex(*station);
        g->addVertex(newStation);
        for (auto& edgeData : edgesData) {
            auto dest = g->findVertex(edgeData.destCode);
            auto source = g->findVertex(edgeData.sourceCode);
            auto newEdge = new Edge(edgeData.capacity, dest, source, edgeData.flow);
            g->addEdge(newEdge);
            source->addEdge(newEdge);
        }
    }
}


void removePipelines(Graph* g){
    auto cities = g->getCities();
    auto pipelines = g->getEdges();
    for (auto pipeline : pipelines) {
        int originalCapacity = pipeline->getCapacity();

        pipeline->setCapacity(0);

        cout << "Rupturing pipeline from " << pipeline->getSource()->getName() << " to " << pipeline->getDest()->getName() << ":" << endl;

        calculateMaxFlowToCities(g);

        for (auto city : cities) {
            double totalFlow = 0;

            for (auto edge : city->getAdj()) {
                totalFlow += edge->getFlow();
            }

            if (totalFlow < city->getDemand()) {
                double deficit = city->getDemand() - totalFlow;
                cout << "City: " << city->getName() << " | Deficit: " << deficit << endl;
            }
        }

        pipeline->setCapacity(originalCapacity);
    }
}
