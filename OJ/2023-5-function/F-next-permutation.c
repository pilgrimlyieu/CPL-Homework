#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arrangement[n], m = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &arrangement[i]);
    for (int i = n - 1; i > 0; i--) {
        m++;
        if (arrangement[i] > arrangement[i - 1])
            break;
    }
    int p_k_index = n - m - 1, p_k = arrangement[p_k_index], num = arrangement[p_k_index + 1], num_index = p_k_index + 1;
    for (int i = n - m; i < n; i++) {
        if (arrangement[i] < num && arrangement[i] > p_k) {
            num_index = i;
            num = arrangement[i];
        }
    }
    arrangement[num_index] = p_k;
    arrangement[p_k_index] = num;
    for (int i = 0; i < n - m; i++)
        printf("%d ", arrangement[i]);
    for (int i = n - 1; i >= n - m; i--)
        printf("%d ", arrangement[i]);
    return 0;
}