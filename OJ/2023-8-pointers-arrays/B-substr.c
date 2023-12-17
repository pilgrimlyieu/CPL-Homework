#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *haystack = malloc(100005), *needle = malloc(100005);
    int h = -1, n = -1;
    while (scanf("%c", haystack + ++h) != EOF && *(haystack + h) != '\n');
    while (scanf("%c", needle + ++n) != EOF && *(needle + n) != '\n');
    for (int i = 0; i < h; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (*(needle + j) != *(haystack + i + j)) {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("%d ", i);
    }
    free(haystack);
    free(needle);
    return 0;
}
