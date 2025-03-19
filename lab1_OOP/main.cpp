#include <iostream>
#include <fstream>
#include "price.h"

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int totalHryvnia = 0, totalKopiykas = 0;
    string inputMethod;
    cout << "Enter 'file' to read from data.txt or 'console' to enter data manually: ";
    cin >> inputMethod;

    ifstream inputFile;
    bool useFile = (inputMethod == "file");
    if (useFile) {
        inputFile.open("data.txt");
        if (!inputFile) {
            cerr << "Error opening file. Switching to manual input." << endl;
            useFile = false;
        } else {
            cout << "Reading data from data.txt..." << endl;
        }
    }

    if (!useFile) {
        cout << "Enter data in the format: hryvnia kopiykas quantity (for example: 19 89 3)." << endl;
        cout << "To finish, use an incorrect format." << endl;
    }

    int h, k, quantity;
    while ((useFile ? inputFile : cin) >> h >> k >> quantity) {
        int itemHryvnia, itemKopiykas;
        multiplyPrices(h, k, quantity, itemHryvnia, itemKopiykas);
        addPrices(totalHryvnia, totalKopiykas, itemHryvnia, itemKopiykas, totalHryvnia, totalKopiykas);
    }

    if (useFile) {
        inputFile.close();
    }

    int roundedHryvnia = totalHryvnia, roundedKopiykas = totalKopiykas;
    roundToNatBank(roundedHryvnia, roundedKopiykas);

    cout << "\nTotal price: " << totalHryvnia << " hryvnia " << totalKopiykas << " kopiykas" << endl;
    cout << "Rounded price: " << roundedHryvnia << " hryvnia " << roundedKopiykas << " kopiykas" << endl;

    return 0;
}
