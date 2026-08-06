#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;

    // 1. Get and Validate Dimensions
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error: Matrix multiplication is not possible. Columns of A must match rows of B.\n");
        return 1;
    }

    // 2. Runtime Allocation (Array of pointers, then rows)
    int **A = (int **)malloc(r1 * sizeof(int *));
    int **B = (int **)malloc(r2 * sizeof(int *));
    int **C = (int **)malloc(r1 * sizeof(int *));

    for (int i = 0; i < r1; i++) A[i] = (int *)malloc(c1 * sizeof(int));
    for (int i = 0; i < r2; i++) B[i] = (int *)malloc(c2 * sizeof(int));
    for (int i = 0; i < r1; i++) C[i] = (int *)calloc(c2, sizeof(int));

    // 3. Populate Matrices
    printf("\nEnter elements of Matrix A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);
 

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // 4. Matrix Multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // 5. Display Result
    printf("\nProduct of the matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // 6. Memory Deallocation (Free dynamically allocated space)
    for (int i = 0; i < r1; i++) free(A[i]);
    for (int i = 0; i < r2; i++) free(B[i]);
    for (int i = 0; i < r1; i++) free(C[i]);
    
    free(A); free(B); free(C);

    return 0;
}
