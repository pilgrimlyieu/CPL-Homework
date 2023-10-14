#include <stdio.h>

int main(void) {
    int n, result = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int temp_result = 1;
        for (int j = 2; j <= i; j++) {
            temp_result = (j * temp_result) % 10007;
        }
        result += (temp_result % 10007);
    }
    printf("%d", result % 10007);
    return 0;
}
