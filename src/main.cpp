#include "../data_structures/read.h"
#include "ex1.h"
#include <iostream>

using namespace std;

int main(){

    int choice;
    int choice2;
    string vertChoice;
    
    while (true) {
        cout << "##### Choose Dataset #####" << endl;
        cout << "1. Small DataSet" << endl;
        cout << "2. Large DataSet" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;
        
        switch (choice) {
            case 1:
            {
                Graph graph = read::populate();
                while (true){
                    cout << "##### Choose Operation #####" << endl;
                    cout << "1. (2.1) Calculate Max Flow to all Cities" << endl;
                    cout << "2. (2.1) Calculate Flow to Specific City" << endl;
                    cout << "3. (2.2) Print Deficits" << endl;
                    cout << "4. (3.1) Unavailable reservoir" << endl;
                    cout << "X. Back to main menu" << endl;
                    cout << "Enter your choice: ";
                    
                    cin >> choice2;

                    switch (choice2) {
                    case 1:
                    {
                        calculateMaxFlowToCities(&graph, nullptr);
                        break;
                    }
                    case 2:
                    {
                        cout << "Write the name of the city:" << endl;

                        cin >> vertChoice;
                        auto vertex = graph.findvertexByName(vertChoice);
                        if (vertex == nullptr){
                            cout << "Invalid name" << endl;
                            break;
                        }
                        calculateMaxFlowToCities(&graph, vertex);
                        graph.clearSupers();
                        break;
                    }
                    case 3:
                    {
                        printDeficits(&graph);
                        break;
                    }
                    case 4:
                    {
                        cout << "Write the code of the reservoir to be put outof comission:" << endl;
                    }
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                    }
                }
            }
            case 2:
            {
                cout << "Option 2" << endl;
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        main_menu: cout << endl;
    };
    
    return 0;
}