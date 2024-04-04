#include "../data_structures/read.h"
#include <iostream>

using namespace std;

int main(){
    /**
        int choice;
        
        while (choice != 4) {
            cout << "Menu:" << endl;
            cout << "1. Option 1" << endl;
            cout << "2. Option 2" << endl;
            cout << "3. Option 3" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            
            cin >> choice;
            
            switch (choice) {
                case 1:
                    cout << "Option 1 selected." << endl;
                    break;
                case 2:
                    cout << "Option 2 selected." << endl;
                    break;
                case 3:
                    cout << "Option 3 selected." << endl;
                    break;
                case 4:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
            
            cout << endl;
        };
        
        return 0;
    **/


    Graph graph = read::populate();
    for (auto v: graph.getVertexSet()){
        cout << v->getCode();
    }


}