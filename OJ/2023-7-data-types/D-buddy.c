#include <stdio.h>

int size2(int n) {
    int s = 0, i = 1;
    while (i < n) {
        s += 1;
        i *= 2;
    }
    return s;
}

void split(int mem[], int size[], int len, int pos) {
    size[pos] -= 1;
    for (int i = len; i >= pos; i--) {
        mem[i + 1] = mem[i];
        size[i + 1] = size[i];
    }
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);
    int mem[n + q], sizes[n + q], start = 0, len = 1;
    mem[0] = 0, mem[1] = -1, sizes[0] = n, sizes[1] = -1;
    for (int i = 0; i < q; i++) {
        getchar();
        char c = getchar();
        if (c == 'Q') {
            printf("%d\n", len);
            for (int j = 0; mem[j] != -1; j++)
                printf("%d ", mem[j]);
            printf("\n");
        }
        else {
            int id, m;
            scanf("%d %d", &id, &m);
            int size = size2(m), set = 0;
            while (1) {
                for (int j = start; j < len; j++) {
                    if (sizes[j] == size && mem[j] == 0) {
                        mem[j] = id;
                        set = 1;
                        break;
                    }
                }
                if (set)
                    break;
                for (int j = start; j < len; j++) {
                    if (sizes[j] > size && mem[j] == 0) {
                        split(mem, sizes, len, j);
                        len++;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}