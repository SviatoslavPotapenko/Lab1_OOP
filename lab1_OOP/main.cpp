#include "lab1.h"
#include <iostream>

int main() {
    Price total = calculateTotalPrice("prices.txt");
    Price rounded_total = total;
    roundPrice(rounded_total);

    std::cout << "Загальна сума: " << total.hryvnias << " грн " << total.kopecks << " коп" << std::endl;
    std::cout << "Сума до оплати (з округленням): " << rounded_total.hryvnias << " грн " << rounded_total.kopecks << " коп" << std::endl;

    return 0;
}
