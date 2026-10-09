#include <iostream>
using namespace std;

class Matrix {
    int a[2][2];

public:
    Matrix(int x[2][2]) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = x[i][j];
    }

    Matrix operator+(const Matrix& m) const {
        int result[2][2];

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result[i][j] = a[i][j] + m.a[i][j];

        return Matrix(result);
    }

    void display() const {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int x[2][2] = {{1, 2}, {3, 4}};
    int y[2][2] = {{5, 6}, {7, 8}};

    Matrix m1(x), m2(y);
    Matrix m3 = m1 + m2;

    cout << "First Matrix:\n";
    m1.display();

    cout << "Second Matrix:\n";
    m2.display();

    cout << "Resultant Matrix:\n";
    m3.display();

    return 0;
}