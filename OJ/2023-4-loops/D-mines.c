#include <stdio.h>

int main(void) {
    int n, counters[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1,-1 }, { 1, 0 }, { 1, 1 } };
    scanf("%d", &n);
    char map[n + 2][n + 2];
    for (int i = 0; i <= n + 1; i++)
        map[0][i] = 'o', map[n + 1][i] = 'o', map[i][0] = 'o', map[i][n + 1] = 'o';
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= n; j++)
            scanf("%c", &map[i][j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == '*')
                printf("*");
            else {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    if (map[i + counters[k][0]][j + counters[k][1]] == '*')
                        count++;
                }
                printf("%d", count);
            }
        }
        printf("\n");
    }
    return 0;
}
