#ifndef LAB1_H
#define LAB1_H

#include <string>

struct Price {
    int hryvnias;
    short int kopecks;
};

Price createPrice(int h = 0, int k = 0);
Price addPrices(const Price& a, const Price& b);
Price multiplyPrice(const Price& price, int quantity);
void roundPrice(Price& price);
Price calculateTotalPrice(const std::string& filename);

#endif // LAB1_H
