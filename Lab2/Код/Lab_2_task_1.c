#include <stdio.h>
#include <math.h>

int main() {
    double x = 2.0;
    int n;
    int i, j;
    double product = 1.0;
    double sum_j;
    long long op_count = 0;

    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid input. n must be >= 1.\n");
        return 1;
    }

    op_count++;
    for (i = 1; i <= n; i++) {
        sum_j = 0.0;
        op_count += 4;

        for (j = 1; j <= i; j++) {
            op_count += 6;
            sum_j += (4 * j - 1);
        }

        product *= (1.0 - ((1.0 + x) * (1.0 + x)) / (4.0 * sum_j));
        op_count += 6;
    }

    double pi = acos(-1.0);
    double P = cos(pi * x / 4.0) - sin(pi * x / 4.0) * sqrt(2.0) * product;
    op_count += 10;

    printf("P = %.7f\n", P);
    printf("Operations = %lld\n", op_count);

    return 0;
}