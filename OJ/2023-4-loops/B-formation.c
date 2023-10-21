#include <stdio.h>

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    getchar();
    char row_1[n + 2], students[m][n + 2];
    row_1[0] = '0', row_1[n + 1] = '0';
    for (int i = 1; i <= n; i++) {
        scanf("%c", &row_1[i]);
    }
    for (int i = 0; i <= n + 1; i++) {
        students[0][i] = row_1[i];
    }
    for (int i = 1; i < m; i++) {
        students[i][0] = '0', students[i][n + 1] = '0';
        for (int j = 1; j <= n; j++) {
            students[i][j] = (\
               (students[i - 1][j - 1] == '1' && students[i - 1][j] == '1' && students[i - 1][j + 1] == '1')\
            ||  (students[i - 1][j - 1] == '1' && students[i - 1][j] == '0' && students[i - 1][j + 1] == '0')\
            ||  (students[i - 1][j - 1] == '0' && students[i - 1][j] == '0' && students[i - 1][j + 1] == '0')\
            ) ? '0' : '1';
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", students[i][j]);
        }
        printf("\n");
    }
    return 0;
}