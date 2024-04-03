#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "matrix_operations.h"

// Helper function to compare matrices with tolerance due to floating-point arithmetic
bool matricesAreEqual(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B, double tolerance = 1e-6) {
    if (A.size() != B.size() || A[0].size() != B[0].size()) return false;
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            if (std::abs(A[i][j] - B[i][j]) > tolerance) return false;
        }
    }
    return true;
}

TEST_CASE("Matrix multiplication - Basic multiplication") {
    std::vector<std::vector<double>> A = {
        {1, 2},
        {3, 4}
    };
    std::vector<std::vector<double>> B = {
        {5, 6},
        {7, 8}
    };
    std::vector<std::vector<double>> expected = {
        {19, 22},
        {43, 50}
    };
    auto result = multiplyMatrices(A, B);
    CHECK(matricesAreEqual(result, expected));
}

TEST_CASE("Normalization of matrix - Simple normalization") {
    int n = 2; 
    double base = 3 * (n + 1);
    std::vector<std::vector<double>> C = {
        {base, 1.0 / base},
        {1.0 / base, base}
    };
    std::vector<std::vector<double>> expected = {
        {1, -1},
        {-1, 1}
    };
    normalizeMatrix(C, n);
    CHECK(matricesAreEqual(C, expected));
}