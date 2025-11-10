#include <iostream>
using namespace std;

class Matrix {
    int matrix[3][3];

public:
    Matrix() {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                matrix[i][j] = 0;
    }

    void input() {
        cout << "Enter 3x3 matrix elements:\n";
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin >> matrix[i][j];
    }

    Matrix operator+(Matrix m) {
        Matrix res;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                res.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        return res;
    }

    friend Matrix operator*(Matrix a, Matrix b) {
        Matrix res;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++) {
                res.matrix[i][j] = 0;
                for(int k=0;k<3;k++)
                    res.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
            }
        return res;
    }

    void display() {
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2, sum, prod;
    cout << "Matrix 1:\n";
    m1.input();
    cout << "Matrix 2:\n";
    m2.input();

    sum = m1 + m2;
    prod = m1 * m2;

    cout << "\nSum of matrices:\n";
    sum.display();

    cout << "\nProduct of matrices:\n";
    prod.display();

    return 0;
}
