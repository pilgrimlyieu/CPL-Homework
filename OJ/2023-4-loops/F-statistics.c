#include <stdio.h>

int main(void) {
    int n, max = 0, index = 0, alphabet_1[26] = { 0 }, alphabet_2[26] = { 0 };
    scanf("%d", &n);
    char s[n], bottom[78];
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            alphabet_1[s[i] - 'a']++;
            max = (alphabet_1[s[i] - 'a'] > max) ? alphabet_1[s[i] - 'a'] : max;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            alphabet_2[s[i] - 'A']++;
            max = (alphabet_2[s[i] - 'A'] > max) ? alphabet_2[s[i] - 'A'] : max;
        }
    }
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < 26; j++) {
            printf((alphabet_1[j]) ? (i >= max - alphabet_1[j]) ? "=" : " " : "");
            printf((alphabet_2[j]) ? (i >= max - alphabet_2[j]) ? "=" : " " : "");
            if (alphabet_1[j] || alphabet_2[j]) {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet_1[i]) {
            bottom[index++] = 'a' + i;
        }
        if (alphabet_2[i]) {
            bottom[index++] = 'A' + i;
        }
        if (alphabet_1[i] || alphabet_2[i]) {
            bottom[index++] = ' ';
        }
    }
    bottom[index - 1] = '\0';
    for (int i = 0; i < index - 1; i++) {
        printf("-");
    }
    printf("\n%s", bottom);
    return 0;
}