#pragma once
#include <iostream>
#include <string>

using namespace std;

class Matrix {
private:
    static const int MAX_N = 10; // Максимально можливий розмір масиву
    int count;                   // Поточна кількість елементів (поточний розмір N)
    int data[MAX_N][MAX_N];

public:
    // Конструктори
    Matrix();
    Matrix(int n);
    Matrix(const Matrix& other);

    // Методи доступу з контролем значень
    int getCount() const;
    void setCount(int n);
    int getElement(int i, int j) const;
    void setElement(int i, int j, int value);

    // Метод генерації елементів 
    void Create();

    // Обчислення норми матриці
    double norm() const;

    // Обов'язкові операції
    Matrix& operator=(const Matrix& other);
    int* operator[](int index);
    const int* operator[](int index) const;
    operator string() const;

    // Бінарні операції (зовнішні дружні функції)
    friend Matrix operator*(const Matrix& left, const Matrix& right);
    friend bool operator==(const Matrix& left, const Matrix& right);
    friend bool operator!=(const Matrix& left, const Matrix& right);

    friend ostream& operator<<(ostream& out, const Matrix& m);
    friend istream& operator>>(istream& in, Matrix& m);
};