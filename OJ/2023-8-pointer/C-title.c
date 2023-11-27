#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *str = malloc(4096);
    int len = -1, first = 1;
    while (scanf("%c", str + ++len) != EOF) {
        if (first) {
            first = 0;
            if ('a' <= *(str + len) && *(str + len) <= 'z')
                printf("%c", *(str + len) - 'a' + 'A');
            else
                printf("%c", *(str + len));
        }
        else {
            if ('A' <= *(str + len) && *(str + len) <= 'Z')
                printf("%c", *(str + len) - 'A' + 'a');
            else
                printf("%c", *(str + len));
            if (*(str + len) == ' ')
                first = 1;
        }
    }
    free(str);
    return 0;
}