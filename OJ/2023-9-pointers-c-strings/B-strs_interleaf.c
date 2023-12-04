#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void interleaveString(char* s1, char* s2, int d1, int d2, int size) {
    char *s = malloc(size * sizeof(s)), *idx1 = s1, *idx2 = s2;
    int len = 0, len1 = strlen(s1), len2 = strlen(s2);
    while (1) {
        if (len == size - 1 || (idx1 >= s1 + len1 && idx2 >= s2 + len2))
            goto finish;
        int l1 = (idx1 + d1 > s1 + len1) ? len1 - (idx1 - s1) : d1;
        for (int _ = 0; _ < l1; _++) {
            *(s + len++) = *(idx1++);
            if (len == size - 1)
                goto finish;
        }
        int l2 = (idx2 + d2 > s2 + len2) ? len2 - (idx2 - s2) : d2;
        for (int _ = 0; _ < l2; _++) {
            *(s + len++) = *(idx2++);
            if (len == size - 1)
                goto finish;
        }
    }
    finish:
    *(s + len) = '\0';
    puts(s);
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        char *inp = malloc(2023 * sizeof(inp));
        scanf("%s", inp);
        char *s1 = strtok(inp, ";"), *s2 = strtok(NULL, ";"), *s_d1 = strtok(NULL, ";"), *s_d2 = strtok(NULL, ";"), *s_size = strtok(NULL, ";");
        int d1 = atoi(s_d1), d2 = atoi(s_d2), size = atoi(s_size);
        interleaveString(s1, s2, d1, d2, size);
    }
    return 0;
}