#include <stdio.h>

int main(void) {
    char month[10], weekday[10];
    int day, year, hour, minute, second;
    scanf("%s %d %d %s %d %d %d", month, &day, &year, weekday, &hour, &minute, &second);
    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d", weekday, month, day, hour, minute, second, year);
    return 0;
}
