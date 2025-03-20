#include <iostream>
#include <fstream>
#include "price.h"

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    Price totalAmount = {0, 0}; // Ініціалізація загальної суми

    ifstream fileStream("data.txt");
    if (!fileStream) {
        cout << "Помилка: не вдалося відкрити файл data.txt." << endl;
        return 1; // Завершити програму з кодом помилки
    }

    cout << "Читання даних із файлу data.txt..." << endl;

    int h, quantity;
    short k;

    while (fileStream >> h >> k >> quantity) {
        Price itemPrice = {h, k};
        multiplyCost(itemPrice, quantity);
        sumCosts(totalAmount, itemPrice);
    }

    fileStream.close();

    Price roundedAmount = totalAmount;
    roundToBankRules(roundedAmount.hryvnias, roundedAmount.kopecks);

    cout << "\nЗагальна сума: " << totalAmount.hryvnias << " грн " << totalAmount.kopecks << " коп." << endl;
    cout << "Округлена сума: " << roundedAmount.hryvnias << " грн " << roundedAmount.kopecks << " коп." << endl;

    return 0;
}
