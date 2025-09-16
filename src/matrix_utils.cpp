#include "matrix_utils.h"
#include <random>


int** init_matrix(int size) {
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    for (int i = 0; i < size; i++) {
        matrix[i][i] = 0; 
        for (int j = i + 1; j < size; j++) {
            int val = dist(gen);
            matrix[i][j] = val;
            matrix[j][i] = val; 
        }
    }

    return matrix;
}

void show_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}

void show_col_sums(int* sum_cols, int cols) {
    //std::cout << "Ñףללû סעמכבצמג:\n";
   // for (int j = 0; j < cols; j++)
        //std::cout << "Ñעמכבוצ " << j + 1 << ": " << sum_cols[j] << "\n";
}
