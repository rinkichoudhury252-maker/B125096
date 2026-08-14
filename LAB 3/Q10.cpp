#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, i, j;
    int **matrix1, **matrix2, **result;

    // 1. Accept dimensions
    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    // 2. Dynamically allocate memory for three matrices
    // Allocate array of pointers for rows
    matrix1 = (int **)malloc(m * sizeof(int *));
    matrix2 = (int **)malloc(m * sizeof(int *));
    result  = (int **)malloc(m * sizeof(int *));

    // Check for allocation failure
    if (!matrix1 || !matrix2 || !result) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for each row (columns)
    for (i = 0; i < m; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
        matrix2[i] = (int *)malloc(n * sizeof(int));
        result[i]  = (int *)malloc(n * sizeof(int));
        
        // Check for row allocation failure
        if (!matrix1[i] || !matrix2[i] || !result[i]) {
            printf("Memory allocation failed.\n");
            // Cleanup previously allocated rows
            for (int k = 0; k < i; k++) {
                free(matrix1[k]);
                free(matrix2[k]);
                free(result[k]);
            }
            free(matrix1);
            free(matrix2);
            free(result);
            return 1;
        }
    }

    // 3. Accept elements of first matrix
    printf("Enter elements of Matrix 1:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // 4. Accept elements of second matrix
    printf("Enter elements of Matrix 2:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // 5. Perform matrix addition
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // 6. Display the resulting matrix
    printf("Resulting Matrix (Addition):\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // 7. Properly deallocate all dynamically allocated memory
    for (i = 0; i < m; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}   