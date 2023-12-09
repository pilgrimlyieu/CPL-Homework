#include <stdio.h>
#include <string.h>

int main() {
    char str[1024];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (('a' <= str[i] && str[i] <= 'z') || i == 0)
            printf("%c", str[i]);
        else if ('A' <= str[i] && str[i] <= 'Z')
            printf(" %c", str[i] - 'A' + 'a');
    }
    return 0;
}
