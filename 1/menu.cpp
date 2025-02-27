#include <iostream>
using namespace std;
extern int userChoice;
#include "components.cpp"

int main() {
    bool running = true;
   
    while (running) {
        cout << "\nPress 1 to enter information about tickets\n";
        //TODO add checker of at least one run func of fetchingData till running changing
        cout << "Press 2 to change information\n";
        cout << "Press 3 to output information\n";
        cout << "Press 0 to quit\n";
        userChoiceValidation();

        switch (userChoice) {
            case 1:
                fetchingData();
                cout << "Tickets data successfully fetched\n";
                break;
            case 2:
                changeTicketsData();
                break;
            case 3:
                outputData();
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Enter correct menu option\n";
                break;
        }
    }

    return 0;
}