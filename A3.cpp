#include <iostream>
using namespace std;

class Matrix {
private:
    int** mat;
    int rlimit;
    int climit;

public:
    Matrix(int r, int c) : rlimit(r), climit(c) {
        mat = new int*[rlimit];
        for (int i = 0; i < rlimit; ++i) {
            mat[i] = new int[climit];
        }
    }

    Matrix(const Matrix& m) : rlimit(m.rlimit), climit(m.climit) {
        mat = new int*[rlimit];
        for (int i = 0; i < rlimit; ++i) {
            mat[i] = new int[climit];
            for (int j = 0; j < climit; ++j) {
                mat[i][j] = m.mat[i][j];
            }
        }
    }

    Matrix add(const Matrix& m) const {
        Matrix result(rlimit, climit);
        for (int i = 0; i < rlimit; ++i) {
            for (int j = 0; j < climit; ++j) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    ~Matrix() {
        for (int i = 0; i < rlimit; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }
};

int main() {
    Matrix m1(2, 2);
    Matrix m2 = m1; 
    Matrix m3 = m1.add(m2);

    return 0;
}
