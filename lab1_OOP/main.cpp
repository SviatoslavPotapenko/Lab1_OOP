#include <iostream>
#include <string>

#include "lab1.h"

int main() {
    int hryvnias;
    short kopecks;

    // Обчислення загальної вартості
    calculateTotalPrice("prices.txt", hryvnias, kopecks);

    // Вивід загальної суми
    std::cout << "Загальна сума: " << hryvnias << " грн " << kopecks << " коп." << std::endl;

    // Округлення суми
    roundPrice(hryvnias, kopecks);

    // Вивід округленої суми
    std::cout << "Округлена сума: " << hryvnias << " грн " << kopecks << " коп." << std::endl;

    return 0;
}
