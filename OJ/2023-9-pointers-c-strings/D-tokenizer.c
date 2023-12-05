#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reserved[16] = {"const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"};
char *operators[11] = {"+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};

char* StrTok(char *str, char c) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            str[i] = '\0';
//            return (i == strlen(str) - 1) ? NULL : str + i + 1;
            return str + i + 1;
        }
    }
    return NULL;
}

int if_reserved(char *str) {
    for (int i = 0; i < 16; i++) {
        if (strcmp(str, reserved[i]) == 0)
            return 1;
    }
    return 0;
}

int if_operator(char *str) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(str, operators[i]) == 0)
            return 1;
    }
    return 0;
}

int is_variable(char *str) {
    if (str[0] >= '0' && str[0] <= '9')
        return 0;
    for (int i = 0; i < strlen(str); i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == '_'))
            return 0;
    }
    return 1;
}

int is_number(char *str) {
    int is_float = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (is_float && str[i] == '.')
            return 0;
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
            return 0;
        if (str[i] == '.')
            is_float = 1;
    }
    return (is_float ? 2 : 1);
}

int process(char *str, char *msg) {
    if (str[0] == '\0')
        return 1;
    if (if_reserved(str)) {
        strcat(msg, "reserved ");
        return 1;
    }
    else if (if_operator(str)) {
        strcat(msg, "operator ");
        return 1;
    }
    else if (is_variable(str)) {
        strcat(msg, "variable ");
        return 1;
    }
    else if (is_number(str) == 1) {
        strcat(msg, "integer ");
        return 1;
    }
    else if (is_number(str) == 2) {
        strcat(msg, "float ");
        return 1;
    }
    return 0;
}

int main(void) {
    char *msg = malloc(5300604 * sizeof(msg));
    char *token = malloc(4096 * sizeof(token));
    while (scanf("%s", token) != EOF) {
        char *pos = token, *next;
        while ((next = StrTok(pos, ';')) != NULL) {
            if (!process(pos, msg)) {
                printf("Compile Error");
                return 0;
            }
            strcat(msg, "\n");
            pos = next;
        }
        if (!process(pos, msg)) {
            printf("Compile Error");
            return 0;
        }
    }
    printf("%s", msg);
    return 0;
}