#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int userChoice;
const int SEASON_ARR_LENGTH = 4;

struct ticketsDataSeason {
    int soldTicketsAmount;
    int price;
    string yearSeason;
    int ticketsRevenue = 0;
};
string SEASON_ARR[4]={"spring", "summer", "autumn", "winter"};
static ticketsDataSeason allTicketsDataSeason[SEASON_ARR_LENGTH];
bool isFetchingDataRun = false;
void fetchingData() {
    for (int i = 0; i < SEASON_ARR_LENGTH; i++) {
        cout << "Enter season: ";
        cin >> allTicketsDataSeason[i].yearSeason;

        while (true) {
            cout << "Enter amount of sold tickets: ";
            cin >> allTicketsDataSeason[i].soldTicketsAmount;
            if( allTicketsDataSeason[i].soldTicketsAmount >=0){
                 if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a number.\n";
                } else {
                    break;
                }  }
        }

        while (true) {
           if(allTicketsDataSeason[i].price>=0){
                cout << "Enter ticket price: ";
                cin >> allTicketsDataSeason[i].price;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a number.\n";
                } else {
                    break;
                }
           }
        }
    }
     
    isFetchingDataRun = true;
}

void revenueCalc() {
    for (int i = 0; i < SEASON_ARR_LENGTH; i++) {
        allTicketsDataSeason[i].ticketsRevenue = allTicketsDataSeason[i].price * allTicketsDataSeason[i].soldTicketsAmount;
    }
}

void changeTicketsData() {
    if (isFetchingDataRun)
    {
        string searchingSeason;
        cout << "Enter season name which information you want to change: ";
        cin >> searchingSeason;
    
        for (int i = 0; i < SEASON_ARR_LENGTH; i++) {
            if (searchingSeason == allTicketsDataSeason[i].yearSeason) {
                cout << "Press 1 to Change ticket price\n";
                cout << "Press 2 to Change amount of sold tickets\n";
                cout << "Press 0 to quit changing\n";
                int p;
                cin >> p;
    
                switch (p) {
                    case 1:
                        while (true) {
                            cout << "Enter new ticket price: ";
                            cin >> allTicketsDataSeason[i].price;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input! Please enter a number.\n";
                            } else {
                                break;
                            }
                        }
                        break;
                    case 2:
                        while (true) {
                            cout << "Enter new amount of sold tickets: ";
                            cin >> allTicketsDataSeason[i].soldTicketsAmount;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input! Please enter a number.\n";
                            } else {
                                break;
                            }
                        }
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Enter correct value\n";
                        break;
                }
                break;
                cout << "Tickets data successfully changed\n";

            }
            else{
                cout << "Enter correct season\n"; break;

            }
        }
    }
    else{
        cout << "Enter some data before editing\n";
    }
    
}

void userChoiceValidation() {
    cout << "Enter your choice: ";
    cin >> userChoice;
}

void outputData() {
    revenueCalc();

    sort(allTicketsDataSeason, allTicketsDataSeason + SEASON_ARR_LENGTH, [](const ticketsDataSeason& a, const ticketsDataSeason& b) {
        return a.ticketsRevenue > b.ticketsRevenue;
    });

    cout << "Season  Price  Sold Tickets  Revenue\n";
    for (int i = 0; i < SEASON_ARR_LENGTH; i++) {
        cout<<allTicketsDataSeason[i].yearSeason;
        printf("%12d", allTicketsDataSeason[i].price );
        printf("%12d",allTicketsDataSeason[i].soldTicketsAmount);
        printf("%12d\n",allTicketsDataSeason[i].ticketsRevenue);
    }
}