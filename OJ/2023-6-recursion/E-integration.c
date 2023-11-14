#include <stdio.h>

double f(int n, const int a[], double x, int p) {
    double result = 0;
    double pows = 1;
    for (int i = 0; i <= n; i++) {
        result += a[i] * pows;
        pows *= x;
    }
    switch (p) {
        case -2:
            return 1 / (result * result);
        case -1:
            return 1 / result;
        case 2:
            return result * result;
        default:
            return result;
    }
}

double integral(double e, int n, int a[], double l, double r, int p) {
    double mid = (l + r) / 2.0;
    double f1 = f(n, a, l, p), f2 = f(n, a, mid, p), f3 = f(n, a, r, p), f4 = f(n, a, (l + mid) / 2.0, p), f5 = f(n, a, (mid + r) / 2.0, p);
    double S = (r - l) * (f1 + 4 * f2 + f3) / 6, SL = (mid - l) * (f1 + 4 * f4 + f2) / 6, SR = (r - mid) * (f2 + 4 * f5 + f3) / 6;
    double epsilon = SL + SR - S;
    if (-15 * e <= epsilon && epsilon <= 15 * e)
        return SL + SR + epsilon / 15;
    else
        return integral(e / 2, n, a, l, mid, p) + integral(e / 2, n, a, mid, r, p);
}

int main(void) {
    int n, p;
    scanf("%d %d", &n, &p);
    int a[21];
    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);
    double l, r;
    scanf("%lf %lf", &l, &r);
    printf("%lf", integral(1e-4, n, a, l, r, p));
    return 0;
}