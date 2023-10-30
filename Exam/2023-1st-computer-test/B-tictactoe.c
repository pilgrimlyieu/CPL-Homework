#include <stdio.h>

int main(void) {
    int t, x;
    scanf("%d %d", &t, &x);
    for (int i = 0; i < t; i++) {
        int n;
        int players[3] = {0};
        scanf("%d", &n);
        int board[n][n];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                scanf("%d", &board[j][k]);
        }

        // 行
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n - x + 1; k++) {
                int result = 7;
                for (int p = 0; p < x; p++)
                    result &= board[j][k + p];
                if (result == 4)
                    players[2]++;
                else if (result == 2)
                    players[1]++;
                else if (result == 1)
                    players[0]++;
            }
        }
        // 列
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n - x + 1; k++) {
                int result = 7;
                for (int p = 0; p < x; p++)
                    result &= board[k + p][j];
                if (result == 4)
                    players[2]++;
                else if (result == 2)
                    players[1]++;
                else if (result == 1)
                    players[0]++;
            }
        }
        // 正对角线 1
        for (int j = 0; j < n - x + 1; j++) {
            for (int k = 0; k < n - x + 1; k++) {
                int result = 7;
                for (int p = 0; p < x; p++)
                    result &= board[j + p][k + p];
                if (result == 4)
                    players[2]++;
                else if (result == 2)
                    players[1]++;
                else if (result == 1)
                    players[0]++;
            }
        }

        for (int j = n - 1; j >= x - 1; j--) {
            for (int k = 0; k < n - x + 1; k++) {
                int result = 7;
                for (int p = 0; p < x; p++)
                    result &= board[j - p][k + p];
                if (result == 4)
                    players[2]++;
                else if (result == 2)
                    players[1]++;
                else if (result == 1)
                    players[0]++;
            }
        }

        if (players[0] > 0 && players[1] == 0 && players[2] == 0)
            printf("1\n");
        else if (players[0] == 0 && players[1] > 0 && players[2] == 0)
            printf("2\n");
        else if (players[0] == 0 && players[1] == 0 && players[2] > 0)
            printf("4\n");
        else
            printf("draw\n");
    }
    return 0;
}
