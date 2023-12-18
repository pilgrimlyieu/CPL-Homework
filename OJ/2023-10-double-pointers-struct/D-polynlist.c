#include <stdio.h>

int main(void) {
    int p1, p2;
    char var[11];
    scanf("%d %d %s", &p1, &p2, var);
    int p_big = (p1 > p2) ? p1 : p2, k1[p_big + 1], k2[p_big + 1];
    for (int i = 0; i <= p_big; i++)
        k1[i] = k2[i] = 0;
    for (int i = p1; i >= 0; i--)
        scanf("%d", &k1[i]);
    for (int i = p2; i >= 0; i--)
        scanf("%d", &k2[i]);
    for (int i = p_big; i >= 0; i--) {
        int k = k1[i] + k2[i];
        if (k == 0)
            continue;
        else if (k > 0 && i != p_big)
            printf("+");
        if (k != 1 && k != -1)
            printf("%d", k);
        else if (k == -1)
            printf("-");
        if (i == 0 && (k == 1 || k == -1))
            printf("1");
        else if (i > 0)
            printf("%s", var);
        if (i > 1)
            printf("^%d", i);
    }
    printf("\n");
    for (int i = p_big; i >= 0; i--) {
        int k = k1[i] - k2[i];
        if (k == 0)
            continue;
        else if (k > 0 && i != p_big)
            printf("+");
        if (k != 1 && k != -1)
            printf("%d", k);
        else if (k == -1)
            printf("-");
        if (i == 0 && (k == 1 || k == -1))
            printf("1");
        else if (i > 0)
            printf("%s", var);
        if (i > 1)
            printf("^%d", i);
    }
    printf("\n");
    for (int i = p1 + p2; i >= 0; i--) {
        int k = 0;
        for (int j = 0; j <= i; j++) {
            if (j > p1 || i - j > p2)
                continue;
            k += k1[j] * k2[i - j];
        }
        if (k == 0)
            continue;
        else if (k > 0 && i != p1 + p2)
            printf("+");
        if (k != 1 && k != -1)
            printf("%d", k);
        else if (k == -1)
            printf("-");
        if (i == 0 && (k == 1 || k == -1))
            printf("1");
        else if (i > 0)
            printf("%s", var);
        if (i > 1)
            printf("^%d", i);
    }
    return 0;
}