#include <stdio.h>

int abs(int a) {
    return a > 0 ? a : -a;
}

int main(void) {
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    int a[n + 2 * d][m + 2 * d], vs[n][m];
    for (int i = 0; i < n + 2 * d; i++) {
        for (int j = 0; j < m + 2 * d; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = d; i < n + d; i++) {
        for (int j = d; j < m + d; j++)
            scanf("%d", &a[i][j]);
    }
    int max = -2147483648, t = 0;
    for (int i = d; i < n + d; i++) {
        int sum = 0;
        for (int j = i - d + 1; j < i + d; j++) {
            for (int k = 1; k < 2 * d + 1; k++) {
                if ((k <= d && abs(i - j) <= k - 1) || ((k > d) && abs(i - j) + k <= 2 * d))
                   sum += a[j][k];
            }
        }
        for (int k = 0; k <= d; k++)
            sum += a[i + d - k][d - k] + a[i + k - d][d - k];
        sum -= a[i][0];
        vs[i - d][0] = sum;
        if (sum > max)
            max = sum;
        for (int j = d + 1; j < m + d; j++) {
            for (int k = 0; k <= d; k++)
                sum += a[i + d - k][j + k] + a[i + k - d][j + k] - a[i + d - k][j - k - 1] - a[i + k - d][j - k - 1];
            sum += a[i][j - d - 1] - a[i][j + d];
            vs[i - d][j - d] = sum;
            if (sum > max)
                max = sum;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vs[i][j] == max)
                t++;
        }
    }
    printf("%d %d\n", max, t);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vs[i][j] == max)
                printf("%d %d\n", i + 1, j + 1);
        }
    }
    return 0;
}