#include <stdio.h>

int main(void) {
    int answer[12] = {
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    for (int i = 0; i < 12; i++)
        printf(answer[i] ? "YES\n" : "NO\n");
    return 0;
}
