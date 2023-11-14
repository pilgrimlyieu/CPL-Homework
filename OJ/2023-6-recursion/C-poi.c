#include <stdio.h>

int poi(int n, int a[]) {
    if (n == a[n])
        return n;
    else
        return poi(a[n], a);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        printf("%d ", poi(i, a));
    return 0;
}