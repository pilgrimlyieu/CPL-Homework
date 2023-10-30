#include <stdio.h>

int main(void) {
    int n, k, b, l;
    scanf("%d %d %d %d", &n, &k, &b, &l);
    int jbs[n + 1];
    for (int i = 1; i <= n; i++)
        jbs[i] = l;
    int bl = b, kill = 0, order = 1;
    while (kill < n * l - 1) {
        int step = 0;
        while (step < k) {
            if (order == n + 1) {
                order = 1;
                continue;
            }
            if (jbs[order])
                step++;
            if (step < k)
                order++;
        }
        if (!bl)
            bl = b;
        else {
//            printf("kill %d;\n", order);
            kill++;
            jbs[order]--;
            bl--;
        }
        order++;
    }
    for (int i = 1; i <= n; i++) {
        if (jbs[i])
            printf("%d", i);
    }
    return 0;
}
