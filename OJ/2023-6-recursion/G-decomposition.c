#include <stdio.h>

void find(int n, int min, int F, int ans[]) {
    if (n == 0) {
        for (int i = 0; i < F; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    if (n < min)
        return;
    for (int i = min; i <= n; i++) {
        ans[F] = i;
        find(n - i, i, F + 1, ans);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int ans[100000] = {0};
    find(n, 1, 0, ans);
    return 0;
}