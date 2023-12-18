#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);
    int *arr = malloc(sizeof(arr) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    while(q--) {
        int x;
        scanf("%d", &x);
        int *p = bsearch(&x, arr, n, sizeof(int), compare);
        printf("%d\n", (p == NULL) ? -1 : (p - arr));
    }
    free(arr);
    return 0;
}