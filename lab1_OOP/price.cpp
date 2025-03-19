#include "price.h"
#include <cmath>

void normal(int& hrn, int& kop) {
    if (kop >= 100) {
        hrn += kop / 100;
        kop %= 100;
    }
}

void addPrices(int h1, int k1, int h2, int k2, int& resultH, int& resultK) {
    resultH = h1 + h2;
    resultK = k1 + k2;
    normal(resultH, resultK);
}

void multiplyPrices(int h, int k, double multiplier, int& resultH, int& resultK) {
    double totalKop = (h * 100 + k) * multiplier;
    int roundedTotal = static_cast<int>(round(totalKop));
    resultH = roundedTotal / 100;
    resultK = roundedTotal % 100;
}

void roundToNatBank(int& hryvnia, int& kopiykas) {
    int remainder = kopiykas % 10;
    if (remainder < 5)
        kopiykas -= remainder;
    else
        kopiykas += (10 - remainder);

    normal(hryvnia, kopiykas);
}

