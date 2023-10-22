#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    char pre[1000], next[1000];
    scanf("%s", pre);
    int len = strlen(pre);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            int count[2] = { 0 };
            for (int k = 1; k <= 3; k++) {
                if (pre[j - k] == 'A')
                    count[0]++;
                else if (pre[j - k] == 'B')
                    count[1]++;
                if (pre[j + k] == 'A')
                    count[0]++;
                else if (pre[j + k] == 'B')
                    count[1]++;
            }
            if (pre[j] == '.') {
                next[j] = (count[0] == 0 && 2 <= count[1] && count[1] <= 4) ? 'B' :
                          (count[1] == 0 && 2 <= count[0] && count[0] <= 4) ? 'A' :
                                                                              '.';
            }
            else {
                next[j] = (count[1 - (pre[j] - 'A')] != 0 || count[pre[j] - 'A'] >= 5 || count[pre[j] - 'A'] <= 1) ? '.' : pre[j];
            }
        }
        strncpy(pre, next, len);
    }
    printf("%s", pre);
    return 0;
}
