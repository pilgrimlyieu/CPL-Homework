#include <stdio.h>

void Sort(int array[], int low, int high) {
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
    Sort(array, low, j);
    Sort(array, j + 1, high);
}

int main(void) {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    int a[n], b[m], min = t;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int j = 0; j < m; j++)
        scanf("%d", &b[j]);
    Sort(b, 0, m - 1);
    int a_index = n - 1;
    while (a_index > 0) {
        int b_low = 0, b_high = m - 1;
        if (a[a_index] > t || a[a_index] == a[a_index + 1]) {
            a_index--;
            continue;
        }
        while (b_low <= b_high) {
            int b_mid = (b_low + b_high) / 2;
            if (b[b_mid] > t) {
                b_high = b_mid - 1;
                continue;
            }
            int sum = a[a_index] + b[b_mid];
            if (sum <= t) {
                int minus = t - sum;
                if (minus <= min)
                    min = minus;
                b_low = b_mid + 1;
            }
            else
                b_high = b_mid - 1;
        }
        a_index--;
    }
    printf("%d", (min == t) ? -1 : min);
    return 0;
}
