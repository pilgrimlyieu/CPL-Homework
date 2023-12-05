#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid(char param, const char *parse, int len) {
    for (int i = 0; i < len; i++) {
        if (*(parse + i) == param)
            return (*(parse + i + 1) == ':') ? 2 : 1;
    }
    return 0;
}

int main(void) {
    char *parse = malloc(128 * sizeof(parse)), *token = malloc(1024 * sizeof(token)), *name = malloc(1024 * sizeof(name)), *msg = malloc(5300604 * sizeof(msg));
    scanf("%s", parse);
    int len = strlen(parse);
    scanf("%s", name);
    strcat(msg, name);
    strcat(msg, "\n");
    while (scanf("%s", token) != EOF) {
        if (token[0] != '-')
            continue;
        switch (valid(token[1], parse, len)) {
            case 0:
                printf("%s: invalid option -- '%c'\n", name, token[1]);
                return 0;
            case 1:
                strcat(msg, token + 1);
                strcat(msg, "\n");
                break;
            case 2: {
                char *param = malloc(1024 * sizeof(param));
                if (scanf("%s", param) == EOF) {
                    printf("%s: option requires an argument -- '%c'\n", name, token[1]);
                    return 0;
                }
                else {
                    strcat(msg, token + 1);
                    strcat(msg, "=");
                    strcat(msg, param);
                    strcat(msg, "\n");
                }
                break;
            }
        }
    }
    printf("%s", msg);
    return 0;
}
