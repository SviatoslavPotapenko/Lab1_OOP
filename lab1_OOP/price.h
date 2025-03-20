#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <cmath>

struct Price {
    int hryvnias;
    short kopecks;
};

void adjustValues(int& hryvnias, short& kopecks);
void sumCosts(Price& total, const Price& additional);
void multiplyCost(Price& price, double factor);
void roundToBankRules(int& hryvnias, short& kopecks);

#endif // PRICE_H
