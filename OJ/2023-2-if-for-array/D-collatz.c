#include <stdio.h>

int main(void) {
    int n, max = 1, count = 0;
    scanf("%d", &n);
    do {
        if (n > max) {
            max = n;
        }
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        count++;
    } while (n != 1);
    printf("%d %d", count, max);
    return 0;
}