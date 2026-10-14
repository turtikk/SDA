#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    int exists = 0;
    if (x > 0 && x <= 5){
        y = pow(x, 3) - 5 * pow(x, 2);
        exists = 1;
    } else if ( x >= -32 && x < -20 || x > 10){
        y = pow(x, 2) - 3;
        exists = 1;
    }
if (exists == 1) {
        printf("value function y = %.2lf\n", y);
    } else {
        printf("function does not exist for the given x.\n");
    }
    return 0;
}