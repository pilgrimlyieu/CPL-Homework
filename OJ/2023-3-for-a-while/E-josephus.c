#include <stdio.h>

int main(void) {
    int n, k, killed = 0;
    scanf("%d %d", &n, &k);
    int alive[n];
    for (int i = 0; i < n; i++) {
        alive[i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int number = 0;
        for (int count = 0; count < k; number++) {
            if (alive[(killed + number) % n] == 1) {
                count++;
            }
        }
        alive[killed = (killed + number - 1) % n] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (alive[i] == 1) {
            printf("%d", i + 1);
            return 0;
        }
    }
}