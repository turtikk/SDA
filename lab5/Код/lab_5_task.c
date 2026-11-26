#include <stdio.h>

int main(void) {
    int m, n;
    int A[10][10];

    printf("Enter matrix dimensions m and n (7..10): ");
    if (scanf("%d %d", &m, &n) != 2 || m < 7 || m > 10 || n < 7 || n > 10) {
        printf("Invalid dimensions!\n");
    } else {
        printf("Enter elements of matrix A[%d][%d]:\n", m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
            }
        }

        printf("\nInitial matrix A[%d][%d]:\n", m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%5d ", A[i][j]);
            }
            printf("\n");
        }

        int compares = 0;
        int assigns = 0;

        for (int row = 0; row < m; row++) {
            for (int i = 1; i < n; i++) {
                int T = A[row][i];
                assigns++;

                int L = 0;
                int R = i;
                while (L < R) {
                    int j = (L + R) / 2;
                    compares++;
                    if (A[row][j] >= T) {
                        L = j + 1;
                    } else {
                        R = j;
                    }
                }

                for (int k = i - 1; k >= R; k--) {
                    A[row][k + 1] = A[row][k];
                    assigns++;
                }
                A[row][R] = T;
                assigns++;
            }
        }

        printf("\nSorted matrix A[%d][%d] (non-increasing rows):\n", m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%5d ", A[i][j]);
            }
            printf("\n");
        }

        printf("\nComparisons (C): %d | Assignments (R): %d\n", compares, assigns);
    }

    return 0;
}