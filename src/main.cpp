#include <iostream>
#include <Windows.h>
#include "array_utils.h"
#include "matrix_utils.h"
#include "student_utils.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    StudentDatabase db;
    int choice;

    do {
        std::cout << "\n�������� �������:\n"
            << "1 - ������� ����� ����. � ���. ���������� �������\n"
            << "2 - ������������� ������� ���������� �������\n"
            << "3 - �������� ������� ������������� �������\n"
            << "4 - ����� �������� �� �������� ���������� �������\n"
            << "5 - ������ �� ����������\n"
            << "0 - �����\n\n"
            << "��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int size = size_arr();
            int* arr = init_arr(size);
            show_arr(arr, size);
            std::cout << "�������: " << maxDiff_arr(arr, size) << "\n";
            delete[] arr;
            break;
        }
        case 2: {
            int size = 10;
            int* arr = init_arr(size);
            show_arr(arr, size);
            delete[] arr;
            break;
        }
        case 3: {
            int size = size_arr();
            int* arr = init_arr(size);
            show_arr(arr, size);
            delete[] arr;
            break;
        }
        case 4: {
            int rows = 0;
            //int* sum_cols = new int[cols];
            std::cout << "������� ����� �������" << std::endl;
            std::cin >> rows;
            int** matrix = init_matrix(rows);
            show_matrix(matrix, rows);
            //show_col_sums(sum_cols, cols);
            for (int i = 0; i < rows; i++) delete[] matrix[i];
            delete[] matrix;
            //delete[] sum_cols;
            break;
        }
        case 5: {
            int subchoice;
            do {
                std::cout << "\n=== ���� ��������� ===\n"
                    << "1. �������� ��������\n"
                    << "2. ������� �� ID\n"
                    << "3. ����� �� �����\n"
                    << "4. �������� ����\n"
                    << "0. �����\n\n"
                    << "��� �����: ";
                std::cin >> subchoice;

                switch (subchoice) {
                case 1: {
                    std::string name, lastName;
                    int nomZach;
                    std::cout << "���: "; std::cin >> name;
                    std::cout << "�������: "; std::cin >> lastName;
                    std::cout << "����� �������: "; std::cin >> nomZach;
                    db.addStudent(name, lastName, nomZach);
                    break;
                }
                case 2: {
                    db.printStudents();
                    int id;
                    std::cout << "������� ID: "; std::cin >> id;
                    db.removeStudentById(id);
                    break;
                }
                case 3: {
                    std::string name;
                    std::cout << "������� ���: "; std::cin >> name;
                    db.findStudentName(name);
                    break;
                }
                case 4:
                    db.printStudents();
                    break;
                case 0:
                    std::cout << "������� � ������� ����...\n";
                    break;
                default:
                    std::cout << "�������� �����!\n";
                }
            } while (subchoice != 0);
            break;
        }
        case 0:
            std::cout << "�����...\n";
            break;
        default:
            std::cout << "�������� �����!\n";
        }
    } while (choice != 0);

    return 0;
}