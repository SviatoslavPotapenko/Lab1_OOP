#include "lab1.h"
#include <iostream>
#include <fstream>

Price createPrice(int h, int k) {
    return {h, static_cast<short>(k)};
}


Price addPrices(const Price& a, const Price& b) {
    int total_kopecks = (a.hryvnias * 100 + a.kopecks) + (b.hryvnias * 100 + b.kopecks);
    return {total_kopecks / 100, static_cast<short>(total_kopecks % 100)};
}

Price multiplyPrice(const Price& price, int quantity) {
    int total_kopecks = (price.hryvnias * 100 + price.kopecks) * quantity;
    return {total_kopecks / 100, static_cast<short>(total_kopecks % 100)};
}

void roundPrice(Price& price) {
    int remainder = price.kopecks % 10;
    if (remainder < 5) {
        price.kopecks -= remainder;
    } else {
        price.kopecks += (10 - remainder);
    }

    if (price.kopecks >= 100) {
        price.hryvnias += price.kopecks / 100;
        price.kopecks %= 100;
    }
}

Price calculateTotalPrice(const std::string& filename) {
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return {0, 0};
    }

    Price total = {0, 0};
    int hryvnias, kopecks, quantity;

    while (input >> hryvnias >> kopecks >> quantity) {
        Price item_price = createPrice(hryvnias, kopecks);
        total = addPrices(total, multiplyPrice(item_price, quantity));
    }

    input.close();
    return total;
}
