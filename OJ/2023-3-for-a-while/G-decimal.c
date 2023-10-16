#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    int len, N, result = 0;
    scanf("%d %d", &len, &N);
    char s[len], chars[] = "0123456789ABCDEF";
    scanf("%s", s);
    int l = strlen(s);
    for (int i = l - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (s[i] == chars[j]) {
                result += j * pow(N, l - i - 1);
                goto next;
            }
        }
        printf("Error\n");
        return 0;
        next:
    }
    printf("%d\n", result);
    return 0;
}