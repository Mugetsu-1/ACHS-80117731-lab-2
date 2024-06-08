#include <stdio.h>
#include <stdbool.h>


void displayMatrix(bool matrix[3][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to perform join (OR) operation on two matrices
void join(bool A[3][3], bool B[3][3], bool result[3][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] | B[i][j];
        }
    }
}

// Function to perform meet (AND) operation on two matrices
void meet(bool A[3][3], bool B[3][3], bool result[3][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] & B[i][j];
        }
    }
}

// Function to perform Boolean product on two matrices
void booleanProduct(bool A[3][3], bool B[3][3], bool result[3][3], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = false;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] |= (A[i][k] & B[k][j]);
            }
        }
    }
}

int main() {
    bool A[3][3] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 0}
    };

    bool B[3][3] = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}
    };

    bool joinResult[3][3];
    bool meetResult[3][3];
    bool productResult[3][3];

    printf("Matrix A:\n");
    displayMatrix(A, 3, 3);

    printf("Matrix B:\n");
    displayMatrix(B, 3, 3);

    join(A, B, joinResult, 3, 3);
    printf("Join (A OR B):\n");
    displayMatrix(joinResult, 3, 3);

    meet(A, B, meetResult, 3, 3);
    printf("Meet (A AND B):\n");
    displayMatrix(meetResult, 3, 3);

    booleanProduct(A, B, productResult, 3, 3, 3);
    printf("Boolean Product (A * B):\n");
    displayMatrix(productResult, 3, 3);

    return 0;
}