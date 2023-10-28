#include <stdio.h>

int valid(int num, int B) { // 偷个懒。。。
    return num / 10 < B && num % 10 < B;
}

int to_ten(int num, int B) { // 偷个懒。。。
    return num / 10 * B + num % 10;
}

int main(void) {
    int p, q, r;
    scanf("%d %d %d", &p, &q, &r);
    for (int B = 2; B <= 40; B++) {
        if (valid(p, B) && valid(q, B) && valid(r, B) && to_ten(p, B) * to_ten(q, B) == to_ten(r, B)) {
            printf("%d", B);
            return 0;
        }
    }
    printf("0");
    return 0;
}