#include <stdio.h>

#define MAX_SIZE 10

int isSymmetric(int matrix[][MAX_SIZE], int rows, int cols) {
    int i, j;

    // Check if the matrix is square
    if (rows != cols)
        return 0;

    // Check if the matrix is symmetric
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i])
                return 0;
        }
    }

    return 1;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    int i, j;

    printf("Enter the number of rows (maximum %d): ", MAX_SIZE);
    scanf("%d", &rows);

    printf("Enter the number of columns (maximum %d): ", MAX_SIZE);
    scanf("%d", &cols);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is symmetric
    if (isSymmetric(matrix, rows, cols))
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}
