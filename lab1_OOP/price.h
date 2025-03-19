#include <iostream>
#include <cmath>

struct Price {
    int hrn;
    int kop;
};

void normal(int& hrn, int& kop);
void addPrices(int h1, int k1, int h2, int k2, int& resultH, int& resultK);
void multiplyPrices(int h, int k, double multiplier, int& resultH, int& resultK);
void roundToNatBank(int& hrn, int& kop);
