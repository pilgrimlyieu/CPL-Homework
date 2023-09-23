#include <stdio.h>

int main() {
    double G = 6.674e-11, M = 77.15, m, R;
    scanf("%le %le", &m, &R);
    printf("%.3le", G * M * m / (R * R));
    return 0;
}
