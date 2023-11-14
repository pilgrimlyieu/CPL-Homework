#include <stdio.h>

long long binomial(int n, int i) {
    if (i == 0 || n == i)
        return 1;
    else
        return binomial(n - 1, i - 1) + binomial(n - 1, i);
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld", binomial(a - 1, b - 1));
    return 0;
}