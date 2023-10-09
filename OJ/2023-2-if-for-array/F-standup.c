#include <stdio.h>

int main(void) {
    int max, sum = 0, largest = 0;
    scanf("%d", &max);
    int students[max];
    for (int i = 0; i <= max; i++) {
        scanf("%d", &students[i]);
        if (i - sum > largest) {
            largest = i - sum;
        }
        sum += students[i];
    }
    printf("%d", largest);
    return 0;
}