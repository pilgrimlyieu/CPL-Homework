#include <stdio.h>

int main(void) {
    int number;
    scanf("%d", &number);
    printf("%d %c\n%d %c", number, number, number + 32, number + 32);
    return 0;
}
