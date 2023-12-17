#include <stdio.h>

int main(void) {
    int x;
    scanf("%x", &x);
    int *p = &x;
    unsigned int *q = (unsigned int *) &x;
    float *r = (float *) &x;
    printf("%d\n%u\n%.6f\n%.3e", *p, *q, *r, *r);
    return 0;
}