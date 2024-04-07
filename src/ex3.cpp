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