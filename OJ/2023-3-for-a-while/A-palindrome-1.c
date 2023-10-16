#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        printf("%c", (str[i] == '?') ? str[n - 1 - i] : str[i]);
    }
    return 0;
}