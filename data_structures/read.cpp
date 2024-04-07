#include "read.h"

Graph read::populate_large() {

    Graph graph;
    unordered_map<string, Vertex*> vertexMap;
    ifstream stations;
    ifstream reservoirs;
    ifstream cities;
    ifstream pipes;

    //ler estacoes
    stations.open("data/large_data/Stations.csv");
    if (!stations.is_open()){
        cout << "error stations file";
        return graph;
    }


    string linha;
    getline(stations, linha);

    while(getline(stations, linha)){
        stringstream line(linha);
        string buff;
        auto* temp = new Vertex();
        temp->setType("station");

        getline(line, buff, ',');
        getline(line, buff, ',');
        temp->setCode(buff);

        vertexMap[temp->getCode()] = temp;

    }
    stations.close();



    reservoirs.open("data/large_data/Reservoir.csv");

    if (!reservoirs.is_open()){
        cout << "error reservoirs";
        return graph;
    }

    getline(reservoirs, linha);
    while(getline(reservoirs, linha)){
        stringstream line(linha);
        string buff;
        auto* temp = new Vertex();
        temp->setType("reservoir");

        getline(line, buff, ',');
        temp->setName(buff);
        getline(line, buff, ',');
        temp->setMunicipality(buff);
        getline(line, buff, ',');
        getline(line, buff, ',');
        temp->setCode(buff);
        getline(line, buff, ',');
        temp->setMaxDelivery(stoi(buff));
        vertexMap[temp->getCode()] = temp;
    }

    reservoirs.close();
    cities.open("data/large_data/Cities.csv");
    if (!cities.is_open()){
        cout << "error cities file";
        return graph;
    }


    getline(cities, linha);
    while(getline(cities, linha)){
        stringstream line(linha);
        string buff;
        auto* temp = new Vertex();
        temp->setType("city");

        getline(line, buff, ',');
        temp->setName(buff);
        getline(line, buff, ',');
        getline(line, buff, ',');
        temp->setCode(buff);
        getline(line, buff, ',');
        temp->setDemand(stod(buff));
        getline(line, buff);
        //buff.erase(std::remove(buff.begin(), buff.end(), '\"' ), buff.end());
        //buff.erase(std::remove(buff.begin(), buff.end(), ',' ), buff.end());
        temp->setPopulation(stoi(buff));


        vertexMap[temp->getCode()] = temp;
    }
    cities.close();


    // Connect

    pipes.open("data/large_data/Pipes.csv");
    if (!pipes.is_open()){
        cout << "error pipes file";
        return graph;
    }

    getline(pipes, linha);
    while(getline(pipes, linha)){
        stringstream line(linha);
        string serviceA;
        string serviceB;
        string capacity;
        string direction;

        getline(line, serviceA, ',');
        getline(line, serviceB, ',');
        getline(line, capacity, ',');
        getline(line, direction, ',');

        int capacity2 = stoi(capacity);
        int direction2 = stoi(direction);


        Edge* e = new Edge(capacity2, vertexMap[serviceB], vertexMap[serviceA], 0);
        vertexMap[serviceA]->addEdge(e);
        graph.addEdge(e);

        if (direction2 == 0) {
            Edge* f = new Edge(capacity2, vertexMap[serviceA], vertexMap[serviceB], 0);
            vertexMap[serviceB]->addEdge(f);
            graph.addEdge(f);
        }
    }
    pipes.close();

    for (auto& pair : vertexMap) {
        graph.addVertex(pair.second);
    }


    return graph;
}


Graph read::populate() {
    
    Graph graph;
    unordered_map<string, Vertex*> vertexMap;
    ifstream stations;
    ifstream reservoirs;
    ifstream cities;
    ifstream pipes;

    //ler estacoes
    stations.open("data/Stations_Madeira.csv");
    if (!stations.is_open()){
        cout << "error stations file";
        return graph;
    }


    string linha;
    getline(stations, linha);

    while(getline(stations, linha)){
    stringstream line(linha);
    string buff;
    auto* temp = new Vertex();
    temp->setType("station");

    getline(line, buff, ',');
    getline(line, buff, ',');
    temp->setCode(buff);

    vertexMap[temp->getCode()] = temp;

    }
    stations.close();



    reservoirs.open("data/Reservoirs_Madeira.csv");

    if (!reservoirs.is_open()){
        cout << "error reservoirs";
        return graph;
    }

    getline(reservoirs, linha);
    while(getline(reservoirs, linha)){
        stringstream line(linha);
        string buff;
        auto* temp = new Vertex();
        temp->setType("reservoir");

        getline(line, buff, ',');
        temp->setName(buff);
        getline(line, buff, ',');
        temp->setMunicipality(buff);
        getline(line, buff, ',');
        getline(line, buff, ',');
        temp->setCode(buff);
        getline(line, buff, ',');
        temp->setMaxDelivery(stoi(buff));
        vertexMap[temp->getCode()] = temp;     
    }

    reservoirs.close();
    cities.open("data/Cities_Madeira.csv");
    if (!cities.is_open()){
        cout << "error cities file";
        return graph;
    }


    getline(cities, linha);
    while(getline(cities, linha)){
        stringstream line(linha);
        string buff;
        auto* temp = new Vertex();
        temp->setType("city");

        getline(line, buff, ',');
        temp->setName(buff);
        getline(line, buff, ',');
        getline(line, buff, ',');
        temp->setCode(buff);
        getline(line, buff, ',');
        temp->setDemand(stod(buff));
        getline(line, buff);
        buff.erase(std::remove(buff.begin(), buff.end(), '\"' ), buff.end());
        buff.erase(std::remove(buff.begin(), buff.end(), ',' ), buff.end());
        temp->setPopulation(stoi(buff));


        vertexMap[temp->getCode()] = temp;
    }
    cities.close();

    
    // Connect 

    pipes.open("data/Pipes_Madeira.csv");
    if (!pipes.is_open()){
        cout << "error pipes file";
        return graph;
    }

    getline(pipes, linha);
    while(getline(pipes, linha)){
        stringstream line(linha);
        string serviceA;
        string serviceB;
        string capacity;
        string direction;

        getline(line, serviceA, ',');
        getline(line, serviceB, ',');
        getline(line, capacity, ',');
        getline(line, direction, ',');

        int capacity2 = stoi(capacity);
        int direction2 = stoi(direction);

        
        Edge* e = new Edge(capacity2, vertexMap[serviceB], vertexMap[serviceA], 0);
        vertexMap[serviceA]->addEdge(e);
        graph.addEdge(e);

        if (direction2 == 0) {
            Edge* f = new Edge(capacity2, vertexMap[serviceA], vertexMap[serviceB], 0);
            vertexMap[serviceB]->addEdge(f);
            graph.addEdge(f);
        }
    }
    pipes.close();

    for (auto& pair : vertexMap) {
        graph.addVertex(pair.second);
    }


    return graph;
};