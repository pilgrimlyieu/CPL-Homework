#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int square[n][n], row = 0, col = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            square[i][j] = 0;
    }
    square[row][col] = 1;
    for (int i = 1; i < n * n; i++) {
        int row_ = (row == 0) ? n - 1 : row - 1;
        int col_ = (col == n - 1) ? 0 : col + 1;
        int not_valid = square[row_][col_];
        while (not_valid) {
            row_ = (row == n - 1) ? 0 : row + 1;
            col_ = col;
            not_valid = square[row_][col];
        }
        square[row = row_][col = col_] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", square[i][j]);
        printf("\n");
    }
    return 0;
}