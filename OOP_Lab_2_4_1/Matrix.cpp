#include "Matrix.h"
#include <sstream>
#include <cmath>
#include <cstdlib>

// Конструктор за умовчанням
Matrix::Matrix() : count(1) {
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            data[i][j] = 0;
}

// Конструктор ініціалізації
Matrix::Matrix(int n) {
    setCount(n);
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            data[i][j] = 0;
}

// Конструктор копіювання
Matrix::Matrix(const Matrix& other) : count(other.count) {
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            data[i][j] = other.data[i][j];
}

int Matrix::getCount() const { return count; }

void Matrix::setCount(int n) {
    if (n > 0 && n <= MAX_N) count = n;
    else {
        cerr << "Помилка: розмір поза межами (1..." << MAX_N << ")." << endl;
        count = 1;
    }
}

int Matrix::getElement(int i, int j) const {
    if (i >= 0 && i < count && j >= 0 && j < count) return data[i][j];
    cerr << "Помилка індексу!" << endl;
    return 0;
}

void Matrix::setElement(int i, int j, int value) {
    if (i >= 0 && i < count && j >= 0 && j < count) data[i][j] = value;
    else cerr << "Помилка індексу!" << endl;
}

void Matrix::Create() {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            data[i][j] = rand() % 10;
        }
    }
}

double Matrix::norm() const {
    double sumSq = 0;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            sumSq += data[i][j] * data[i][j];
        }
    }
    return sqrt(sumSq);
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        count = other.count;
        for (int i = 0; i < MAX_N; ++i)
            for (int j = 0; j < MAX_N; ++j)
                data[i][j] = other.data[i][j];
    }
    return *this;
}

int* Matrix::operator[](int index) {
    if (index < 0 || index >= count) {
        cerr << "Помилка індексу!" << endl;
        exit(1);
    }
    return data[index];
}

const int* Matrix::operator[](int index) const {
    if (index < 0 || index >= count) {
        cerr << "Помилка індексу!" << endl;
        exit(1);
    }
    return data[index];
}

Matrix::operator string() const {
    stringstream ss;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            ss << data[i][j] << "\t";
        }
        ss << "\n";
    }
    return ss.str();
}

Matrix operator*(const Matrix& left, const Matrix& right) {
    if (left.count != right.count) {
        cerr << "Помилка: розміри не збігаються для добутку." << endl;
        return Matrix();
    }
    Matrix res(left.count);
    for (int i = 0; i < left.count; ++i) {
        for (int j = 0; j < left.count; ++j) {
            res.data[i][j] = 0;
            for (int k = 0; k < left.count; ++k) {
                res.data[i][j] += left.data[i][k] * right.data[k][j];
            }
        }
    }
    return res;
}

bool operator==(const Matrix& left, const Matrix& right) {
    if (left.count != right.count) return false;
    for (int i = 0; i < left.count; ++i) {
        for (int j = 0; j < left.count; ++j) {
            if (left.data[i][j] != right.data[i][j]) return false;
        }
    }
    return true;
}

bool operator!=(const Matrix& left, const Matrix& right) {
    return !(left == right);
}

ostream& operator<<(ostream& out, const Matrix& m) {
    out << string(m);
    return out;
}

istream& operator>>(istream& in, Matrix& m) {
    int n;
    cout << "Введіть розмірність N (макс " << m.MAX_N << "): ";
    in >> n;
    m.setCount(n);

    m.Create();
     //for (int i = 0; i < m.count; ++i) {
     //    for (int j = 0; j < m.count; ++j) {
     //        cout << "R[" << i << "][" << j << "] = ";
     //       in >> m.data[i][j];
     //    }
     //}
    return in;
}