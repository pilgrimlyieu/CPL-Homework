#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char result[21], number[15];
        int positive = 1;
        scanf("%s", number);
        getchar();
        if (strcmp(number, "0") == 0) {
            printf("0\n");
            goto cont;
        }
        for (int j = 0; j < strlen(number); j++) {
            if (j == 0 && number[j] == '-' && number[j + 1] != '0') {
                positive = -1;
                continue;
            }
            if (!isdigit(number[j])) {
                printf("Radix Error\n");
                goto cont;
            }
        }
        int num = positive * atoi(number), index = 0, addidion = 0;
        while (num) {
            result[index++] = num % 3;
            num /= 3;
        }
        result[index] = 0;
        char ternary[21];
        for (int i = 0; i <= index; i++) {
            result[i] += addidion;
            addidion = (result[i] > 1);
            if (positive == 1) {
                ternary[i] = (result[i] == 1) ? '1' : (result[i] == 2) ? 'Z' : '0';
            }
            else {
                ternary[i] = (result[i] == 1) ? 'Z' : (result[i] == 2) ? '1' : '0';
            }
        }
        for (int i = index; i >= 0; i--) {
            if (i == index && ternary[i] == '0') {
                continue;
            }
            printf("%c", ternary[i]);
        }
        printf("\n");
        cont:
    }
    return 0;
}