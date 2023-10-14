#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char ternary[15];
        scanf("%s", ternary);
        getchar();
        int result = 0, len = strlen(ternary), error = 0;
        for (int j = 0; j < len; j++) {
            switch (ternary[j]) {
                case 'Z':
                    result -= pow(3, len - j - 1);
                case '0':
                    break;
                case '1':
                    result += pow(3, len - j - 1);
                    break;
                default:
                    error = 1;
            }
        }
        printf(error ? "Radix Error\n" : "%d\n", result);
    }
    return 0;
}