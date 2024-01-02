#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m;

typedef struct HashMap {
    int cnt;
    char *strs[100];
} HashMap;

int Hash(char *s) {
    int len = strlen(s), ret = 0;
    for (int i = 0; i < len; i++) {
        ret = (ret + s[i] * (i + 1)) % m;
    }
    return ret;
}

int main(void) {
    int q;
    scanf("%d %d", &m, &q);
    HashMap **Maps = malloc(sizeof(HashMap*) * m);
    for (int i = 0; i < m; i++) {
        Maps[i] = NULL;
    }
    for (int i = 0; i < m; i++) {
        char str[1005];
        scanf("%s", str);
        int hash = Hash(str);
        if (Maps[hash] == NULL) {
            Maps[hash] = malloc(sizeof(HashMap));
            Maps[hash]->cnt = 0;
        }
        Maps[hash]->strs[Maps[hash]->cnt++] = malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(Maps[hash]->strs[Maps[hash]->cnt - 1], str);
    }
    while (q--) {
        char str[1005];
        scanf("%s", str);
        int hash = Hash(str), flag = 0;
        if (Maps[hash] != NULL) {
            for (int i = 0; i < Maps[hash]->cnt; i++) {
                if (strcmp(Maps[hash]->strs[i], str) == 0) {
                    flag = 1;
                    break;
                }
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}