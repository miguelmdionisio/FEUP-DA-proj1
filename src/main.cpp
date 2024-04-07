#include "../data_structures/read.h"
#include "ex1.h"
#include "ex3.h"
#include <iostream>

using namespace std;

int main(){

    int choice;
    int choice2;
    int maxFlowChoice;
    int choice3;
    string vertChoice;
    string cityName;
    
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

                while (true)    {
                    cout << "##### Choose Operation #####" << endl;
                    cout << "1. 2.1 | 2.2 | 2.3" << endl;
                    cout << "2. 3.1 | 3.2 | 3.3" << endl;
                    cout << "3. (3.1) Unavailable reservoir" << endl;
                    cout << "4. Back to main menu" << endl;
                    cout << "Enter your choice: ";
                    
                    cin >> choice2;

                    switch (choice2) {
                case 1:
                {
                    Graph graph = read::populate();
                    calculateMaxFlowToCities(&graph);
                    while (true) {
                        cout << "Choose What you want to consult:" << endl;
                        cout << "1. Max Flow for all cities" << endl;
                        cout << "2. Max Flow for a given city" << endl;
                        cout << "3. Show Deficits" << endl;
                        cout << "4. Back to previous menu" << endl;
                        cin >> maxFlowChoice;

                        switch (maxFlowChoice)  {
                            case 1:
                                showFlowAll(&graph);
                                break;
                            case 2:
                                cout << "City Name:" << endl;
                                cin >> cityName;
                                showFlowCity(&graph, cityName);
                                break;
                            case 3:
                                showDeficits(&graph);
                                break;
                            case 4:
                                goto previous_menu;
                        }
                    }
                    previous_menu: cout << endl;
                    break;
                }
                case 2:
                {
                    Graph graph = read::populate();
                    while (true) {
                        cout << "Choose your operation:" << endl;
                        cout << "1 - Remove Reservoir:" << endl;
                        cout << "2 - 3.2" << endl;
                        cout << "3 - 3.3" << endl;
                        cout << "4. Back to previous menu" << endl;
                        cin >> choice3;

                        switch (choice3){
                            case 1:
                                cout << "Type the code of the reservoir:" << endl;
                                cin >> vertChoice;
                                removeReservoir(&graph, vertChoice);
                                break;
                            case 2:
                                // Add code for 3.2 here
                                break;
                            case 3:
                                // Add code for 3.3 here
                                break;
                            case 4:
                                goto previous_menu2;
                        }
                    }
                    previous_menu2: cout << endl;
                    break;
                }
                    case 3:
                    {
                        // Add code for unavailable reservoir here
                        break;
                    }
                    case 4:
                    {
                        goto main_menu;
                    }
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                    }
                }
            }
            case 2:
            {
                // Add code for Large DataSet here
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