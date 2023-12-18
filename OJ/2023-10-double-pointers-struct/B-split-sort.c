#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*((char **) a), *((char **) b));
}

int main(void) {
    char *haystack = malloc(10100 * sizeof(haystack)), needle[2], *str[100];
    scanf("%s %s", haystack, needle);
    int len = 0;
    char *token = strtok(haystack, needle);
    while (token != NULL) {
        str[len++] = token;
        token = strtok(NULL, needle);
    }
    qsort(str, len, sizeof(char *), compare);
    for (int i = 0; i < len; i++) {
        printf("%s\n", str[i]);
    }
    return 0;
}