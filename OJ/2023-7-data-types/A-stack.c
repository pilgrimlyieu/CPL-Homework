#include <stdio.h>
#include <string.h>

int main(void) {
    int n, index = 0;
    scanf("%d", &n);
    char stack[n];
    for (int i = 0; i < n; i++) {
        char action[6];
        scanf("%s", action);
        if (strcmp(action, "push") == 0) {
            getchar();
            char m = getchar();
            stack[index++] = m;
        }
        else if (strcmp(action, "pop") == 0) {
            if (index)
                index--;
            else
                printf("Empty\n");
        }
        else if (strcmp(action, "top") == 0) {
            if (index)
                printf("%c\n", stack[index - 1]);
            else
                printf("Empty\n");
        }
        else if (strcmp(action, "print") == 0) {
            if (index) {
                for (int j = index - 1; j >= 0; j--)
                    printf("| %c |\n", stack[j]);
                printf("|===|\n");
            }
            else
                printf("Empty\n");
        }
    }
    return 0;
}
