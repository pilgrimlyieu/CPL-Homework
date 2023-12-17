#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    char steps[1000];
    scanf("%s", steps);
    int ps[8][3] = {
        {a, 0, 0},
        {a, b, 0},
        {0, b, 0},
        {0, 0, 0},
        {a, 0, c},
        {a, b, c},
        {0, b, c},
        {0, 0, c}
    }, bs[4] = {0, 1, 2, 3}, ts[4] = {4, 5, 6, 7};
    for (int i = 0; steps[i] != '\0'; i++) {
        char ch = steps[i];
        switch (ch) {
            case 'W': {
                int d1 = ps[bs[0]][0] - ps[bs[3]][0], d2 = ps[ts[0]][2] - ps[bs[0]][2];
                ps[bs[0]][0] -= d1, ps[bs[1]][0] -= d1, ps[bs[0]][2] += d1, ps[bs[1]][2] += d1;
                ps[ts[0]][0] -= d1 + d2, ps[ts[1]][0] -=  d1 + d2, ps[ts[0]][2] += d1 - d2, ps[ts[1]][2] += d1 - d2;
                ps[ts[2]][0] -= d2, ps[ts[3]][0] -= d2, ps[ts[2]][2] -= d2, ps[ts[3]][2] -= d2;
                int t0 = ts[0], t1 = ts[1];
                ts[0] = bs[0], ts[1] = bs[1], bs[0] = bs[3], bs[1] = bs[2], bs[3] = ts[3], bs[2] = ts[2], ts[3] = t0, ts[2] = t1;
                break;
            }
            case 'A': {
                int d1 = ps[bs[1]][1] - ps[bs[0]][1], d2 = ps[ts[0]][2] - ps[bs[0]][2];
                ps[bs[1]][1] -= d1, ps[bs[2]][1] -= d1, ps[bs[1]][2] += d1, ps[bs[2]][2] += d1;
                ps[ts[1]][1] -= d1 + d2, ps[ts[2]][1] -= d1 + d2, ps[ts[1]][2] += d1 - d2, ps[ts[2]][2] += d1 - d2;
                ps[ts[0]][1] -= d2, ps[ts[3]][1] -= d2, ps[ts[0]][2] -= d2, ps[ts[3]][2] -= d2;
                int t0 = ts[0], t3 = ts[3];
                ts[0] = ts[1], ts[3] = ts[2], ts[1] = bs[1], ts[2] = bs[2], bs[1] = bs[0], bs[2] = bs[3], bs[0] = t0, bs[3] = t3;
                break;
            }
            case 'S': {
                int d1 = ps[bs[0]][0] - ps[bs[3]][0], d2 = ps[ts[3]][2] - ps[bs[3]][2];
                ps[bs[2]][0] += d1, ps[bs[3]][0] += d1, ps[bs[2]][2] += d1, ps[bs[3]][2] += d1;
                ps[ts[2]][0] += d1 + d2, ps[ts[3]][0] += d1 + d2, ps[ts[2]][2] += d1 - d2, ps[ts[3]][2] += d1 - d2;
                ps[ts[0]][0] += d2, ps[ts[1]][0] += d2, ps[ts[0]][2] -= d2, ps[ts[1]][2] -= d2;
                int t0 = ts[0], t1 = ts[1];
                ts[0] = ts[3], ts[1] = ts[2], ts[3] = bs[3], ts[2] = bs[2], bs[3] = bs[0], bs[2] = bs[1], bs[0] = t0, bs[1] = t1;
                break;
            }
            case 'D': {
                int d1 = ps[bs[1]][1] - ps[bs[0]][1], d2 = ps[ts[1]][2] - ps[bs[1]][2];
                ps[bs[0]][1] += d1, ps[bs[3]][1] += d1, ps[bs[0]][2] += d1, ps[bs[3]][2] += d1;
                ps[ts[0]][1] += d1 + d2, ps[ts[3]][1] += d1 + d2, ps[ts[0]][2] += d1 - d2, ps[ts[3]][2] += d1 - d2;
                ps[ts[1]][1] += d2, ps[ts[2]][1] += d2, ps[ts[1]][2] -= d2, ps[ts[2]][2] -= d2;
                int t0 = ts[0], t3 = ts[3];
                ts[0] = bs[0], ts[3] = bs[3], bs[0] = bs[1], bs[3] = bs[2], bs[1] = ts[1], bs[2] = ts[2], ts[1] = t0, ts[2] = t3;
                break;
            }
        }
    }
    int x_min = ps[bs[0]][0], x_max = ps[bs[0]][0], y_min = ps[bs[0]][1], y_max = ps[bs[0]][1];
    for (int i = 1; i < 4; i++) {
        if (ps[bs[i]][0] < x_min)
            x_min = ps[bs[i]][0];
        if (ps[bs[i]][0] > x_max)
            x_max = ps[bs[i]][0];
        if (ps[bs[i]][1] < y_min)
            y_min = ps[bs[i]][1];
        if (ps[bs[i]][1] > y_max)
            y_max = ps[bs[i]][1];
    }
    printf("%d %d %d %d", x_min, x_max, y_min, y_max);
    return 0;
}
