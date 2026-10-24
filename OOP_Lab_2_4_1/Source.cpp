#include <iostream>
#include <ctime>
#include <windows.h>
#include "Matrix.h"

// Перевірка розміру з вирівнюванням
#pragma pack(push, 1)
class MatrixPacked {
    int count;
    int data[10][10];
};
#pragma pack(pop)

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(0));

    cout << "--- Перевірка розміру класу ---" << endl;
    cout << "Розмір класу Matrix без #pragma pack(1): " << sizeof(Matrix) << " байт" << endl;
    cout << "Розмір класу з #pragma pack(1): " << sizeof(MatrixPacked) << " байт\n" << endl;

    // Створення об'єктів та генерація елементів
    Matrix R1(3);
    R1.Create();
    cout << "Матриця R1:\n" << R1;
    cout << "Норма R1: " << R1.norm() << "\n" << endl;

    Matrix R2(3);
    R2.Create();
    cout << "Матриця R2:\n" << R2;

    // Демонстрація добутку
    Matrix R3 = R1 * R2;
    cout << "Добуток R3 = R1 * R2:\n" << R3;

    // Демонстрація порівняння
    cout << "Перевірка рівності R1 == R2: " << (R1 == R2 ? "Так" : "Ні") << "\n" << endl;

    // Демонстрація масиву об'єктів та індексування
    Matrix arr[2];
    arr[0].setCount(2);
    arr[0].Create();
    cout << "Елемент масиву arr[0]:\n" << arr[0];

    arr[0][0][0] = 99; // Перевірка перевантаженого оператора []
    cout << "arr[0] після зміни arr[0][0][0] = 99:\n" << arr[0];

    // Демонстрація вводу 
    cout << "Введення матриці з клавіатури (використає Create):" << endl;
    Matrix R4;
    cin >> R4;
    cout << "Згенерована матриця R4:\n" << R4;

    return 0;
}