#include <stdio.h>

int is_prime(int num) {
    for (int i = 2; i * 2 <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int swap(int num) {
    int result = 0;
    while (num) {
        result = result * 10 + num % 10;
        num /= 10;
    }
    return result;
}

int main(void) {
    int n, num = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (is_prime(i) && is_prime(swap(i)))
            num++;
    }
    printf("%d", num);
    return 0;
}