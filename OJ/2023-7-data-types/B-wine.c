#include <stdio.h>

void Sort(int array[], int order[], int low, int high) {
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
            int temp = array[i], temp_o = order[i];
            array[i] = array[j];
            array[j] = temp;
            order[i] = order[j];
            order[j] = temp_o;
        }
    }
    Sort(array, order, low, j);
    Sort(array, order, j + 1, high);
}

int main(void) {
    int n, L, value = 0;
    scanf("%d %d", &n, &L);
    int vs[n], ws[n], os[n];
    for (int i = 0; i < n; i++)
        os[i] = i;
    for (int i = 0; i < n; i++)
        scanf("%d", &vs[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &ws[i]);
    Sort(vs, os, 0, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        int w = ws[os[i]], v = vs[i];
        if (L >= w) {
            value += v * w;
            L -= w;
        }
        else {
            value += v * L;
            break;
        }
    }
    printf("%d", value);
    return 0;
}