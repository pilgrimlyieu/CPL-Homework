#include <stdio.h>

int main() {
    int rmb;
    scanf("%d", &rmb);
    int rmb_in_50 = rmb / 50;
    int rmb_in_20 = (rmb -= 50 * rmb_in_50) / 20;
    int rmb_in_10 = (rmb -= 20 * rmb_in_20) / 10;
    int rmb_in_5  = (rmb -= 10 * rmb_in_10) / 5;
    int rmb_in_1  = rmb - 5 * rmb_in_5;
    printf("%d\n%d\n%d\n%d\n%d", rmb_in_50, rmb_in_20, rmb_in_10, rmb_in_5, rmb_in_1);
    return 0;
}