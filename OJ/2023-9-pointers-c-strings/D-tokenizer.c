#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reserved[16] = {"const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"};
char *operators[11] = {"+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};

char* StrTok(char *str, char c) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            str[i] = '\0';
            return str + i + 1;
        }
    }
    return NULL;
}

int what(char *str) {
    for (int i = 0; i < 16; i++) {
        if (strcmp(str, reserved[i]) == 0)
            return 1;
    }
    for (int i = 0; i < 11; i++) {
        if (strcmp(str, operators[i]) == 0)
            return 2;
    }
    int is_var = 1, is_num = 1;
    if (str[0] >= '0' && str[0] <= '9')
        is_var = 0;
    for (int i = 0; i < strlen(str) && is_var; i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == '_'))
            is_var = 0;
    }
    if (is_var)
        return 3;
    for (int i = 0; i < strlen(str) && is_num; i++) {
        if (is_num == 2 && str[i] == '.')
            is_num = 0;
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
            is_num = 0;
        if (is_num == 1 && str[i] == '.')
            is_num = 2;
    }
    if (is_num)
        return (is_num == 2 ? 5 : 4);
    return 0;
}

void process(char *str, char *msg) {
    if (str[0] == '\0')
        return;
    switch (what(str)) {
        case 0: printf("Compile Error"); exit(0);
        case 1: strcat(msg, "reserved "); break;
        case 2: strcat(msg, "operator "); break;
        case 3: strcat(msg, "variable "); break;
        case 4: strcat(msg, "integer ");  break;
        case 5: strcat(msg, "float ");    break;
    }
}

int main(void) {
    char *msg = malloc(5300604 * sizeof(msg)), *token = malloc(4096 * sizeof(token));
    while (scanf("%s", token) != EOF) {
        char *pos = token, *next;
        while ((next = StrTok(pos, ';')) != NULL) {
            process(pos, msg);
            strcat(msg, "\n");
            pos = next;
        }
        process(pos, msg);
    }
    printf("%s", msg);
    return 0;
}
