#include <stdio.h>
#include <math.h>

int main(void) {
    double x, result = 0;
    int n;
    scanf("%lf %d", &x, &n);
    for (int i = 0; i <= n; i++) {
        result += (i % 2 == 0 ? 1.0 : -1.0) * pow(x, 2 * i + 1) / (2 * i + 1);
    }
    printf("%.10lf", 4 * result);
}