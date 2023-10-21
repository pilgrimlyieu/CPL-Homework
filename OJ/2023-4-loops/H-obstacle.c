#include <stdio.h>
#include <math.h>

int main(void) {
    long x_a, y_a, x_b, y_b, x_c, y_c;
    scanf("%ld %ld %ld %ld %ld %ld", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
    if (x_a == x_b && x_b == x_c) {
        int y_len = labs(y_a - y_b), y_len_1 = labs(y_a - y_c), y_len_2 = labs(y_b - y_c);
        if (y_len != y_len_1 + y_len_2) {
            printf("%d\n", y_len);
            for (int i = 0; i < y_len; i++) {
                printf("%c", y_a > y_b ? 'D' : 'U');
            }
        }
        else {
            printf("%d\n", y_len + 2);
            for (int i = 0; i < y_len_1 - 1; i++) {
                printf("%c", y_a > y_c ? 'D' : 'U');
            }
            printf("R%c%cL", y_a > y_c ? 'D' : 'U', y_a > y_c ? 'D' : 'U');
            for (int i = 0; i < y_len_2 - 1; i++) {
                printf("%c", y_c > y_b ? 'D' : 'U');
            }
        }
    }
    else if (y_a == y_b && y_b == y_c) {
        int x_len = labs(x_a - x_b), x_len_1 = labs(x_a - x_c), x_len_2 = labs(x_b - x_c);
        if (x_len != x_len_1 + x_len_2) {
            printf("%d\n", x_len);
            for (int i = 0; i < x_len; i++) {
                printf("%c", x_a > x_b ? 'L' : 'R');
            }
        }
        else {
            printf("%d\n", x_len + 2);
            for (int i = 0; i < x_len_1 - 1; i++) {
                printf("%c", x_a > x_c ? 'L' : 'R');
            }
            printf("D%c%cU", x_a > x_c ? 'L' : 'R', x_a > x_c ? 'L' : 'R');
            for (int i = 0; i < x_len_2 - 1; i++) {
                printf("%c", x_c > x_b ? 'L' : 'R');
            }
        }
    }
    else {
        int x_len = labs(x_a - x_b), y_len = labs(y_a - y_b);
        printf("%d\n", x_len + y_len);
        if (x_b == x_c) {
            for (int i = 0; i < y_len; i++) {
                printf("%c", y_a > y_b ? 'D' : 'U');
            }
            for (int i = 0; i < x_len; i++) {
                printf("%c", x_a > x_b ? 'L' : 'R');
            }
        }
        else {
            for (int i = 0; i < x_len; i++) {
                printf("%c", x_a > x_b ? 'L' : 'R');
            }
            for (int i = 0; i < y_len; i++) {
                printf("%c", y_a > y_b ? 'D' : 'U');
            }
        }
    }
    return 0;
}