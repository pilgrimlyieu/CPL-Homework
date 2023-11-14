#include <stdio.h>

int Max(int low, int high, const int a[], int b[][2]) {
    if (low > high)
        return 0;
    int max = a[low], p = low;
    for (int i = low + 1; i <= high; i++) {
        if (a[i] > max) {
            max = a[i];
            p = i;
        }
    }
    b[p][0] = low;
    b[p][1] = high;
    Max(low, p - 1, a, b);
    Max(p + 1, high, a, b);
    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n], b[n][2];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Max(0, n - 1, a, b);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", b[i][0] + 1, b[i][1] + 1);
    return 0;
}