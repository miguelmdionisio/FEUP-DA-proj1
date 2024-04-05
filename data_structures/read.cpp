#include "read.h"


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
    Vertex* temp = new Vertex();
    temp->setType("station");

    getline(line, buff, ',');
    getline(line, buff, ','); 
    cout << "Read code: " << buff << endl; 
    temp->setCode(buff);

    vertexMap[temp->getCode()] = temp;

    cout << "deu? - " << vertexMap[buff]->getCode() << endl;
    }
    stations.close();

for (auto v: vertexMap){
        cout << v.first << " - " << v.second->getType() << endl;
    }


    reservoirs.open("data/Reservoirs_Madeira.csv");

    if (!reservoirs.is_open()){
        cout << "error reservoirs";
        return graph;
    }

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
        cout << buff << endl;
        temp->setMaxDelivery(stoi(buff));
        cout << "reservoir ok" << endl;

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
        Vertex* temp = new Vertex();
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
        cout << "cities ok" << endl;


        vertexMap[temp->getCode()] = temp;
    }
    cities.close();



for (auto v: vertexMap){
        cout << v.first << " - "<< v.second->getType() << endl;
    } 
    
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
        
        Edge* e = new Edge(capacity2, vertexMap[serviceB]);
        cout << serviceA << endl;
        vertexMap[serviceA]->getAdj().push_back(e);
    }
    pipes.close();

    for (auto& pair : vertexMap) {
        graph.getVertexSet().push_back(pair.second);

    }

    return graph;
};