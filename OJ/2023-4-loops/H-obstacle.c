#include <stdio.h>
#include <math.h>

int main(void) {
    long x_a, y_a, x_b, y_b, x_c, y_c;
    scanf("%ld %ld %ld %ld %ld %ld", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
    if (x_a == x_b && x_b == x_c) {
        int y_len = abs(y_a - y_b), middle = (abs(y_a - y_c) + abs(y_b - y_c) == y_len);
        printf(middle ? "%d\nR" : "%d\n", middle ? y_len + 2 : y_len);
        for (int i = 0; i < y_len; i++)
            printf("%c", y_a > y_b ? 'D' : 'U');
        if (middle)
            printf("L");
    }
    else if (y_a == y_b && y_b == y_c) {
        int x_len = abs(x_a - x_b), middle = (abs(x_a - x_c) + abs(x_b - x_c) == x_len);
        printf(middle ? "%d\nU" : "%d\n", middle ? x_len + 2 : x_len);
        for (int i = 0; i < x_len; i++)
            printf("%c", x_a > x_b ? 'L' : 'R');
        if (middle)
            printf("D");
    }
    else {
        int x_len = abs(x_a - x_b), y_len = abs(y_a - y_b);
        printf("%d\n", x_len + y_len);
        if (x_b == x_c || y_a == y_c) {
            for (int i = 0; i < y_len; i++)
                printf("%c", y_a > y_b ? 'D' : 'U');
            for (int i = 0; i < x_len; i++)
                printf("%c", x_a > x_b ? 'L' : 'R');
        }
        else {
            for (int i = 0; i < x_len; i++)
                printf("%c", x_a > x_b ? 'L' : 'R');
            for (int i = 0; i < y_len; i++)
                printf("%c", y_a > y_b ? 'D' : 'U');
        }
    }
    return 0;
}
