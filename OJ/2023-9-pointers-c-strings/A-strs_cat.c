#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mystrcat(char* str1, char* str2) {
    int len1 = strlen(str1);
    char *idx = str1 + len1;
    for (char *i = idx; i >= str1; i--) {
        int flag = 1;
        for (int j = 0; j < str1 + len1 - i; j++) {
            if (*(i + j) != *(str2 + j)) {
                flag = 0;
                break;
            }
        }
        if (flag)
            idx = i;
    }
    for (char *i = str1; i < idx; i++)
        putchar(*i);
    puts(str2);
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        char *str1 = malloc(1000 * sizeof(str1)), *str2 = malloc(1000 * sizeof(str2));
        scanf("%s %s", str1, str2);
        mystrcat(str1, str2);
    }
    return 0;
}
