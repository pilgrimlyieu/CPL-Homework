#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        int max = 1;
        for (int k = 0; k < n - 1; k++) {
            max = (a[k] > max) ? a[k] : max;
        }
        printf((max <= a[n - 1]) ? "Yes\n" : "No\n");
    }
    return 0;
}