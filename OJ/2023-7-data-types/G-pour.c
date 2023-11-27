#include <stdio.h>

int Add(int Vm, int m, int n) {
    return (Vm - m >= n) ? m + n : Vm;
}

int Can(int k, int Va, int Vb, int Vc, int a, int b, int c, int a0, int b0, int c0) {
    if (k < 0)
        return 0;
    if (a == a0 && b == b0 && c == c0)
        return 1;
    return Can(k - 1, Va, Vb, Vc, Add(Va, a, b), 0, c, a0, b0, c0) ||
           Can(k - 1, Va, Vb, Vc, Add(Va, a, c), b, 0, a0, b0, c0) ||
           Can(k - 1, Va, Vb, Vc, 0, Add(Vb, b, a), c, a0, b0, c0) ||
           Can(k - 1, Va, Vb, Vc, a, Add(Vb, b, c), 0, a0, b0, c0) ||
           Can(k - 1, Va, Vb, Vc, 0, b, Add(Vc, c, a), a0, b0, c0) ||
           Can(k - 1, Va, Vb, Vc, a, 0, Add(Vc, c, b), a0, b0, c0);
}

int main(void) {
    int k, Va, Vb, Vc, a, b, c, a0, b0, c0;
    scanf("%d %d %d %d %d %d %d %d %d %d", &k, &Va, &Vb, &Vc, &a, &b, &c, &a0, &b0, &c0);
    printf(Can(k, Va, Vb, Vc, a, b, c, a0, b0, c0) ? "Yes" : "No");
    return 0;
}
