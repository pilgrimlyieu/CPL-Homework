#include <stdio.h>

long long pow(long long x, int y) {
    long long result = 1;
    for (int i = 0; i < y; i++)
        result *= x;
    return result;
}

int main(void) {
    long long n;
    int t;
    scanf("%lld %d", &n, &t);
    printf("%lld", t * ((pow(10, n + 1) - 10) / 9 - n) / 9);
    return 0;
}