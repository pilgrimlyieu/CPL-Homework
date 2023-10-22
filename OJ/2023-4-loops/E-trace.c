#include <stdio.h>

int main(void) {
    int n, m, x_0, y_0, steps = 0, counters[5][2] = { { 0, 0 }, { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    scanf("%d %d %d %d", &n, &m, &x_0, &y_0);
    char map[n + 2][m + 2];
    int have_been[n + 2][m + 2], position[2] = { x_0, y_0 }, path[n * m][2];
    for (int i = 0; i <= m + 1; i++)
        map[0][i] = 'o', map[n + 1][i] = 'o';
    for (int i = 1; i <= n; i++) {
        map[i][0] = 'o', map[i][m + 1] = 'o';
        getchar();
        for (int j = 1; j <= m; j++) {
            scanf("%c", &map[i][j]);
            have_been[i][j] = 0;
        }
    }
    for (int can = 1; can; steps++) {
        can = 0;
        for (int i = 0; i < 5; i++) {
            int next_x = position[0] + counters[i][0], next_y = position[1] + counters[i][1], next_ok = !have_been[next_x][next_y];
            if (map[next_x][next_y] == '#' && next_ok) {
                can = 1;
                path[steps][0] = next_x, path[steps][1] = next_y;
                have_been[next_x][next_y] = 1;
                position[0] = next_x, position[1] = next_y;
                break;
            }
        }
    }
    printf("%d\n", steps - 1);
    for (int i = 0; i < steps - 1; i++)
        printf("%d %d\n", path[i][0], path[i][1]);
    return 0;
}
