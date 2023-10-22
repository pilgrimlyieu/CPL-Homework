#include <stdio.h>

int main(void) {
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);
    int matrix_1[m][n], matrix_2[n][p], matrix_r[m][p];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix_1[i][j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++)
            scanf("%d", &matrix_2[i][j]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            matrix_r[i][j] = 0;
            for (int k = 0; k < n; k++)
                matrix_r[i][j] += matrix_1[i][k] * matrix_2[k][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            printf("%d ", matrix_r[i][j]);
        printf("\n");
    }
    return 0;
}
