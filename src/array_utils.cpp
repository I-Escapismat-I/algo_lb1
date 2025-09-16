#include "array_utils.h"
#include <random>

int maxDiff_arr(int* arr, int size) {
    if (size == 0) return 0;
    int max = arr[0], min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    return max - min;
}

int* init_arr(int size) {
    int* arr = new int[size];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 99);

    for (int i = 0; i < size; i++) arr[i] = dist(gen);
    return arr;
}

int size_arr() {
    int size = 0;
    while (size < 1) {
        std::cout << "¬ведите размер массива: ";
        std::cin >> size;
    }
    return size;
}

void show_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}
