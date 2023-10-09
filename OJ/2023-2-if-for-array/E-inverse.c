#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d", &n);
    getchar(); //https://stackoverflow.com/a/61308795/19273614
    char str[n], result[n];
    scanf("%[^\n]\n%d", str, &k);
    for (int i = 0; i < n; i++) {
        result[i] = str[(i < k) ? k - 1 - i : n - 1 - i + k];
    }
    result[n] = '\0'; // 字符串结尾
    printf("%s", result);
    return 0;
}