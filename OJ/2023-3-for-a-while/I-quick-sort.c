#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int pivot = a[k - 1], l = 0, r = n - 1, where;
    while (l < r) {
        while (l < r && a[l] < pivot) {
            l++;
        }
        while (l < r && a[r] >= pivot) {
            r--;
        }
        if (l < r) {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == pivot) {
            where = i;
            break;
        }
    }
    if (a[l] >= pivot) {
        a[where] = a[l];
        a[l] = pivot;
    }
    else if (a[r] < pivot) {
        a[where] = a[r];
        a[r] = pivot;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}