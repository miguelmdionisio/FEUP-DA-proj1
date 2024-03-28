#include "read.h"


Graph read::populate() {
    
    Graph graph;
    unordered_map<string, Vertex*> vertexMap;
    ifstream stations;
    ifstream reservoirs;
    ifstream cities;
    ifstream pipes;

    //ler estacoes
    stations.open("../data/Stations_Madeira.csv");
    if (!stations.is_open()) return graph;


    string linha;
    getline(stations, linha);

    while(getline(stations, linha)){
        stringstream line(linha);
        string buff;
        string code;
        Vertex* temp = new Vertex();
        temp->setType("station");

        getline(line, buff, ',');
        getline(line, code, ',');
        temp->setCode(code);

        //add ao dicionario
        vertexMap[code] = temp;
    }
    stations.close();
    reservoirs.open("../data/Reservoirs_Madeira.csv");

    getline(reservoirs, linha);
    while(getline(reservoirs, linha)){
        stringstream line(linha);
        string buff;
        Vertex* temp = new Vertex();
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
    cities.open("../data/Cities_Madeira.csv");


    getline(cities, linha);
    while(getline(cities, linha)){
        stringstream line(linha);
        string buff;
        Vertex* temp = new Vertex();
        temp->setType("city");

        getline(line, buff, ',');
        temp->setName(buff);
        getline(line, buff, ',');
        getline(line, buff, ',');
        temp->setCode(buff);
        getline(line, buff, ',');
        temp->setDemand(stod(buff));
        getline(line, buff, ',');
        temp->setPopulation(stoi(buff));


        vertexMap[temp->getCode()] = temp;
    }

    // Connect 

    ifstream pipes;
    pipes.open("../data/Pipes_Madeira.csv");

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
        
        Edge* e = new Edge(capacity2, vertexMap[serviceB]);
        vertexMap[serviceA]->getAdj().push_back(e);
    }

    // Iterate through vertexMap and populate graph
    for (auto& pair : vertexMap) {
        graph.getVertexSet().push_back(pair.second);
    }

};