#include <stdio.h>

void triangle(int n, int line, char tri[]) {
    if (n == 1) {
        if (line == 0) {
            tri[0] = ' ';
            tri[1] = '/';
            tri[2] = '\\';
            tri[3] = ' ';
        }
        else {
            tri[0] = '/';
            tri[1] = '_';
            tri[2] = '_';
            tri[3] = '\\';
        }
        return;
    }
    char temp[1 << n];
    if (line < 1 << (n - 1)) {
        triangle(n - 1, line, temp);
        for (int i = 0; i < 1 << (n - 1); i++) {
            tri[i] = ' ';
            tri[(2 << n) - i - 1] = ' ';
        }
        for (int i = 0; i < 1 << n; i++)
            tri[(1 << (n - 1)) + i] = temp[i];
    }
    else {
        triangle(n - 1, line - (1 << (n - 1)), temp);
        for (int i = 0; i < 1 << n; i++) {
            tri[i] = temp[i];
            tri[(1 << n) + i] = temp[i];
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 1 << n; i++) {
        char tri[2 << n];
        triangle(n, i, tri);
//        printf("%s\n", tri);
        for (int j = 0; j < 2 << n; j++)
            printf("%c", tri[j]);
        printf("\n");
    }
    return 0;
}
