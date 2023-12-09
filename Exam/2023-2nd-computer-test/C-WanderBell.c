#include <stdio.h>

int R, C, flag = 1, count = 0;
char map[3000][3000];

int danger(char v, int i, int j) {
    int d = 1;
    switch (v) {
        case 'L': {
            for (int k = 0; k < j; k++) {
                if (map[i][k] != '.') {
                    d = 0;
                    break;
                }
            }
            break;
        }
        case 'R': {
            for (int k = j + 1; k < C; k++) {
                if (map[i][k] != '.') {
                    d = 0;
                    break;
                }
            }
            break;
        }
        case 'U': {
            for (int k = 0; k < i; k++) {
                if (map[k][j] != '.') {
                    d = 0;
                    break;
                }
            }
            break;
        }
        case 'D': {
            for (int k = i + 1; k < R; k++) {
                if (map[k][j] != '.') {
                    d = 0;
                    break;
                }
            }
            break;
        }
    }
    return d;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", &map[i]);
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            switch (map[i][j]) {
                case '.': break;
                case 'L': {
                    if (danger('L', i, j)) {
                        if (!danger('R', i, j)) {
                            count++;
                            map[i][j] = 'R';
                        }
                        else if (!danger('U', i, j)) {
                            count++;
                            map[i][j] = 'U';
                        }
                        else if (!danger('D', i, j)) {
                            count++;
                            map[i][j] = 'D';
                        }
                        else
                            goto death;
                    }
                    break;
                }
                case 'R': {
                    if (danger('R', i, j)) {
                        if (!danger('L', i, j)) {
                            count++;
                            map[i][j] = 'L';
                        }
                        else if (!danger('U', i, j)) {
                            count++;
                            map[i][j] = 'U';
                        }
                        else if (!danger('D', i, j)) {
                            count++;
                            map[i][j] = 'D';
                        }
                        else
                            goto death;
                    }
                    break;
                }
                case 'U': {
                    if (danger('U', i, j)) {
                        if (!danger('L', i, j)) {
                            count++;
                            map[i][j] = 'L';
                        }
                        else if (!danger('R', i, j)) {
                            count++;
                            map[i][j] = 'R';
                        }
                        else if (!danger('D', i, j)) {
                            count++;
                            map[i][j] = 'D';
                        }
                        else
                            goto death;
                    }
                    break;
                }
                case 'D': {
                    if (danger('D', i, j)) {
                        if (!danger('L', i, j)) {
                            count++;
                            map[i][j] = 'L';
                        }
                        else if (!danger('R', i, j)) {
                            count++;
                            map[i][j] = 'R';
                        }
                        else if (!danger('U', i, j)) {
                            count++;
                            map[i][j] = 'U';
                        }
                        else
                            goto death;
                    }
                    break;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
    death:
    printf("-1");
    return 0;
}
