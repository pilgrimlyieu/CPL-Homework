#include <stdio.h>

int main(void) {
    int max, student, sum = 0, largest = 0;
    scanf("%d", &max);
    for (int i = 0; i <= max; i++) {
        scanf("%d", &student);
        if (i - sum > largest) {
            largest = i - sum;
        }
        sum += student;
    }
    printf("%d", largest);
    return 0;
}