#ifndef LAB1_H
#define LAB1_H

#include <string>

struct Price {
    int hryvnias;
    short int kopecks;
};

void createPrice(int h, int k, int& hryvnias, short& kopecks);
void addPrices(int a_h, short a_k, int b_h, short b_k, int& result_h, short& result_k);
void multiplyPrice(int h, short k, int quantity, int& result_h, short& result_k);
void roundPrice(int& hryvnias, short& kopecks);
void calculateTotalPrice(const std::string& filename, int& hryvnias, short& kopecks);


#endif // LAB1_H
