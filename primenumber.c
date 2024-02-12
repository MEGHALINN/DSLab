#include <stdio.h>

int isPrime(int number) {
    if (number <= 1)
        return 0;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    int matrix[100][100];
    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Prime numbers in the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int number = matrix[i][j];
            if (isPrime(number)) {
                printf("%d ", number);
            }
        }
    }
    return 0;
}