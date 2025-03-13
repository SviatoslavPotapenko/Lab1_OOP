#include <iostream>
#include <fstream>
#include <cmath>
#include "lab1.h"

// Функція створення ціни (ініціалізує значення гривень і копійок)
void createPrice(int h, int k, int& hryvnias, short& kopecks) {
    hryvnias = h;
    kopecks = static_cast<short>(k);
}

// Додавання двох цін
void addPrices(int a_h, short a_k, int b_h, short b_k, int& result_h, short& result_k) {
    int total_kopecks = (a_h * 100 + a_k) + (b_h * 100 + b_k);
    result_h = total_kopecks / 100;
    result_k = static_cast<short>(total_kopecks % 100);
}

// Множення ціни на кількість
void multiplyPrice(int h, short k, int quantity, int& result_h, short& result_k) {
    int total_kopecks = (h * 100 + k) * quantity;
    result_h = total_kopecks / 100;
    result_k = static_cast<short>(total_kopecks % 100);
}

// Округлення ціни до найближчої гривні
void roundPrice(int& hryvnias, short& kopecks) {
    if (kopecks >= 50) {
        hryvnias += 1;
    }
    kopecks = 0;
}

// Обчислення загальної суми з файлу
void calculateTotalPrice(const std::string& filename, int& hryvnias, short& kopecks) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return;
    }

    int total_kopecks = 0;
    int h;
    short k;

    while (file >> h >> k) {
        total_kopecks += (h * 100 + k);
    }

    hryvnias = total_kopecks / 100;
    kopecks = static_cast<short>(total_kopecks % 100);
}

