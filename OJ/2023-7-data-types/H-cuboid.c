#include <stdio.h>

void Print(int a, int b, int c) {
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b - i; j++)
            printf("  ");
        for (int j = 0; j < a; j++)
            printf("+-");
        printf("+");
        for (int j = 0; j < i && (i < c || j < c); j++)
            printf(" +");
        printf("\n ");
        for (int j = 0; j < b - i - 1; j++)
            printf("  ");
        for (int j = 0; j < a; j++)
            printf("/ ");
        for (int j = 0; j < i + 1 && (i < c - 1 || j < c); j++)
            printf("/|");
        if (i >= c)
            printf("/");
        printf("\n");
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < a; j++)
            printf("+-");
        printf("+");
        for (int j = 0; (i >= c - b + 1 && j < c - i) || (i < c - b + 1 && j < b); j++)
            printf(" +");
        printf("\n");
        for (int j = 0; j < a; j++)
            printf("| ");
        for (int j = 0; (i >= c - b && j < c - i) || (i < c - b && j < b); j++)
            printf("|/");
        if (i < c - b)
            printf("|");
        printf("\n");
    }
    for (int i = 0; i < a; i++)
        printf("+-");
    printf("+\n");
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        Print(a, b, c);
    }
    return 0;
}