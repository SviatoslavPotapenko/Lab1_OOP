#include "price.h"

void adjustValues(int& hryvnias, short& kopecks) {
    if (kopecks >= 100) {
        hryvnias += kopecks / 100;
        kopecks %= 100;
    }
}

void sumCosts(Price& total, const Price& additional) {
    total.hryvnias += additional.hryvnias;
    total.kopecks += additional.kopecks;
    adjustValues(total.hryvnias, total.kopecks);
}

void multiplyCost(Price& price, double factor) {
    double totalKopecks = (price.hryvnias * 100 + price.kopecks) * factor;
    int roundedTotal = static_cast<int>(round(totalKopecks));
    price.hryvnias = roundedTotal / 100;
    price.kopecks = roundedTotal % 100;
    adjustValues(price.hryvnias, price.kopecks);
}

void roundToBankRules(int& hryvnias, short& kopecks) {
    int remainder = kopecks % 10;
    if (remainder < 5) {
        kopecks -= remainder;
    } else {
        kopecks += (10 - remainder);
    }
    adjustValues(hryvnias, kopecks);
}
