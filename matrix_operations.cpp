#include "matrix_operations.h"
#include <iostream>
#include <vector>
#include <cmath>


std::vector<std::vector<double>> multiplyMatrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int n = A.size();
    std::vector<std::vector<double>> C(n, std::vector<double>(n, 0)); 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (A[i][k] != 0 && B[k][j] != 0) {
                    double product = A[i][k] * B[k][j];
                    C[i][j] += product; 
                }
            }
        }
    }
    return C;
}


void normalizeMatrix(std::vector<std::vector<double>>& A, int n) {
    double base = 3 * (n + 1);
    double zeroEdge = 1; 
    double posEdge = base; 
    double negEdge = 1 / posEdge; 
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == zeroEdge) {
                A[i][j] = 0; 
            } else if (std::abs(A[i][j] - posEdge) < 1e-9 || (A[i][j] > 1 && A[i][j] < posEdge)) {
                A[i][j] = 1; 
            } else if (std::abs(A[i][j] - negEdge) < 1e-9 || (A[i][j] < 1 && A[i][j] > negEdge)) {
                A[i][j] = -1; 
            } else {
                A[i][j] = 0; 
            }
        }
    }
}

/*
int main() {
    int n = 4; 
    
    double base = 3 * (n + 1);
    
    std::vector<std::vector<double>> A(n, std::vector<double>(n, 1)); 
    for (int i = 0; i < n; i++) {
        A[i][(i + 1) % n] = base; 
        A[(i + 1) % n][i] = 1 / base; 
    }


    std::vector<std::vector<double>> C = multiplyMatrices(A, A);

    
    normalizeMatrix(C, n);

    
    std::cout << "Normalized Matrix:\n";
    for (const auto& row : C) {
        for (double elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
*/ 