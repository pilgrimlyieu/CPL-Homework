#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++) {
        char str[100005], s[100005];
        int index = 0, len = 0;
        while (1) {
            char c = getchar();
            if (c == '\n')
                break;
            str[len++] = c;
        }
        for (int j = 0; j < len; j++) {
            if ((str[j] == ')' && s[index - 1] == '(') || (str[j] == ']' && s[index - 1] == '[') || (str[j] == '}' && s[index - 1] == '{'))
                index--;
            else
                s[index++] = str[j];
        }
        printf(index ? "False\n" : "True\n");
    }
    return 0;
}