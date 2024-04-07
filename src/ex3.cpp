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


void removePumpingStations(Graph* g) {
    auto stations = g->getStations();

    for (auto station : stations) {
        string name = station->getName();
        string code = station->getCode();

        g->removeVertex(code);

        calculateMaxFlowToCities(g);

        auto cities = g->getCities();
        bool allDemandsMet = true;

        cout << "Affected cities when pumping station " << name << " (" << code << ") is removed:" << endl;
        for (auto city : cities) {
            for (auto e : city->getAdj()) {
                if (e->getFlow() < city->getDemand()) {
                    allDemandsMet = false;
                    cout << "City Code: " << city->getCode() << " | Water Supply Deficit: " << city->getDemand() - e->getFlow() << endl;
                }
            }
        }

        if (allDemandsMet) {
            cout << "No cities are affected when pumping station " << name << " (" << code << ") is temporarily removed." << endl;
        }

        g->addVertex(station);
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

