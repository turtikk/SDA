#include <stdio.h>

int main(void) {
    int m, n;
    double A[10][10];

    printf("Enter matrix dimensions m and n (7..10): ");
    if (scanf("%d %d", &m, &n) != 2 || m < 7 || m > 10 || n < 7 || n > 10) {
        printf("Invalid dimensions!\n");
    } else {
        printf("Enter elements of matrix A[%d][%d]:\n", m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lf", &A[i][j]);
            }
        }

        printf("\nMatrix A[%d][%d]:\n", m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%6.1f ", A[i][j]);
            }
            printf("\n");
        }

        int L = 0, R = n - 1, bin_steps_row = 0;
        while (L < R) {
            bin_steps_row++;
            int i = (L + R) / 2;
            if (A[0][i] > 5.0)
                L = i + 1;
            else
                R = i;
        }

        int lin_steps_row = 0;
        for (int j = 0; j < n; j++) {
            lin_steps_row++;
            if (A[0][j] >= 0.0 && A[0][j] <= 5.0) {
                break;
            }
        }

        printf("\nFirst row (row 0):\n");
        if (A[0][L] >= 0.0 && A[0][L] <= 5.0) {
            printf("Found %.2f in [0, 5] at coordinates: (0, %d) | Binary steps: %d, Linear steps: %d\n",
                   A[0][L], L, bin_steps_row, lin_steps_row);
        } else {
            printf("No elements in [0, 5] found | Binary steps: %d, Linear steps: %d\n",
                   bin_steps_row, lin_steps_row);
        }

        L = 0;
        R = m - 1;
        int last_col = n - 1, bin_steps_col = 0;
        while (L < R) {
            bin_steps_col++;
            int i = (L + R) / 2;
            if (A[i][last_col] > 5.0)
                L = i + 1;
            else
                R = i;
        }

        int lin_steps_col = 0;
        for (int i = 0; i < m; i++) {
            lin_steps_col++;
            if (A[i][last_col] >= 0.0 && A[i][last_col] <= 5.0) {
                break;
            }
        }

        printf("\nLast column (col %d):\n", last_col);
        if (A[L][last_col] >= 0.0 && A[L][last_col] <= 5.0) {
            printf("Found %.2f in [0, 5] at coordinates: (%d, %d) | Binary steps: %d, Linear steps: %d\n",
                   A[L][last_col], L, last_col, bin_steps_col, lin_steps_col);
        } else {
            printf("No elements in [0, 5] found | Binary steps: %d, Linear steps: %d\n",
                   bin_steps_col, lin_steps_col);
        }
    }

    return 0;
}