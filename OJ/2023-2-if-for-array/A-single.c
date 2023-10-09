#include <stdio.h>

int main(void) {
    int n, temp;
    scanf("%d", &n);
    int array[10 * n + 1];
    for (int i = 0; i < 2 * n - 1; i++) {
        scanf("%d", &temp);
        array[temp] = (array[temp] != -1) ? -1 : -2;
    }
    for (int i = 1; i <= 10 * n; i++) {
        if (array[i] == -1) {
            printf("%d", i);
            return 0;
        }
    }
}
