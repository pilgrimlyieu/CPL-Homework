#include <stdio.h>

int main() {
    int W, N, D;
    scanf("%d %d %d", &W, &N, &D);
    int Ks[W], Do[D], flag = 1;
    long long count = 0;
    for (int i = 0; i < W; i++)
        scanf("%d", &Ks[i]);
    for (int i = 0; 2 * i < W; i++) {
        long long a = (Ks[i] > Ks[W - 1 - i]) ? Ks[W - 1 - i] : Ks[i], b = (Ks[i] > Ks[W - 1 - i]) ? Ks[i] : Ks[W - 1 - i], count_t = 0;
        long long c = 0;
        for (int j = 0; j < D; j++)
            Do[j] = 0;
        while (1) {
            long long r = (b - a + c) % D;
            if (r == 0) {
                count_t = (b - a + c) / D;
                break;
            }
            else if (Do[r]){
                flag = 0;
                break;
            }
            else {
                c += N;
                Do[r]++;
            }
        }
        if (flag) {
            long long count_tt = N - count_t;
            count += (count_tt > count_t) ? count_t : count_tt;
        }
        else
            break;
    }
    if (flag)
        printf("%lld", count);
    else
        printf("Impossible");
    return 0;
}
