#include <iostream>

using namespace std;

int main() {

    int choice;
    string cityCode;

    while (true) {
        cout << "====================================" << endl;
        cout << "Water Supply Management Analysis System" << endl;
        cout << "====================================" << endl;
        cout << "1. Determine the maximum amount of water that can reach a specific city" << endl;
        cout << "2. Determine the maximum amount of water that reach all cities" << endl;
        cout << "3. Check Network Sufficiency" << endl;
        cout << "4. Optimize Network" << endl;
        cout << "5. Evaluate Reliability" << endl;
        cout << "6. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter city code: ";
                cin >> cityCode;
                waterNetwork.calculateMaxFlowToCity(cityCode);
                break;
            case 2:
            waterNetwork.calculateMaxFlowToAllCities(); 
            break;
            case 3:
            waterNetwork.calculateMaxFlowToAllCities(); // This must be called first
            waterNetwork.checkNetworkSufficiency();            
            break;
            case 4:
            cout << "Initial Metrics:" << endl;
            waterNetwork.calculateMetrics();
            waterNetwork.calculateMaxFlowToAllCities(); // This must be called first
            waterNetwork.balanceNetwork();
            cout << "Metrics After Balancing:" << endl;
            waterNetwork.calculateMetrics();
            break;
            // ... handle other cases ...
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid option, please try again." << endl;
        }

        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cin.get();
    }

    return 0;
}
