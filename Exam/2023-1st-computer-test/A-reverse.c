#include <stdio.h>

int main(void) {
    int len;
    scanf("%d", &len);
    char str[len];
    scanf("%s", str);
    for (int i = len - 1; i >= 0; i--) {
        if ('a' <= str[i] && str[i] <= 'z') {
            printf("%c", str[i] - 'a' + 'A');
        }
        else if ('A' <= str[i] && str[i]<= 'Z') {
            printf("%c", str[i] - 'A' + 'a');
        }
        else {
            printf("%c", str[i]);
        }
    }
    return 0;
}
