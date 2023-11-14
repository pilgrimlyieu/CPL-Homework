#include <stdio.h>

int tiles(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return tiles(n - 1) + tiles(n - 2);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", tiles(n));
}