#include <stdio.h>

void sort(int array[], int low, int high) {
    if (low >= high)
        return;
    int i = low - 1, j = high + 1, pivot = array[(low + high) / 2];
    while (i < j) {
        do {
            i++;
        } while (array[i] < pivot);
        do {
            j--;
        } while (array[j] > pivot);
        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    sort(array, low, j);
    sort(array, j + 1, high);
}

int main(void) {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    int a[n], b[m], min = t;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int j = 0; j < m; j++)
        scanf("%d", &b[j]);
    sort(b, 0, m - 1);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > t)
            continue;
        for (int j = m - 1; j >= 0; j--) {
            if (b[j] > t)
                continue;
            int sum = a[i] + b[j];
            if (sum <= t) {
                int minus = t - sum;
                if (minus < min)
                    min = minus;
                break;
            }
        }
    }
    printf("%d", (min == t) ? -1 : min);
    return 0;
}