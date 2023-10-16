#include <stdio.h>

int main(void) {
    int n, times[100] = { 0 }, will[100] = { 0 };
    scanf("%d", &n);
    char str[n];
    int use[n];
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        if (str[i] == '?') {
            if (str[i] == str[n - 1 - i]) {
                if (2 * i < n) {
                    for (int j = 0; j < 100; j++) {
                        if (times[j] < 2 && will[j] < 2 && times[j] + will[j] < 2) {
                            printf("%.2d", j);
                            times[j]++;
                            use[i] = j;
                            will[10 * (j % 10) + j / 10]++;
                            break;
                        }
                    }
                }
                else {
                    printf("%.2d", 10 * (use[n - 1 - i] % 10) + use[n - 1 - i] / 10);
                }
            }
            else {
                printf("%c", str[n - 1 - i]);
            }
        }
        else {
            printf("%c", str[i]);
        }
    }
    return 0;
}