#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char c;
    struct Node *prev, *next, *last_same;
} Node;

int main(void) {
    int Q;
    scanf("%d", &Q);
    Node *str = malloc(sizeof(Node)), *last_lower = NULL, *last_upper = NULL;
    str->prev = NULL;
    str->next = NULL;
    getchar();
    char *string = malloc(sizeof(char) * 2000005);
    while (Q--) {
        scanf("%s", string);
        if (string[0] == '?') {
            int n;
            scanf("%d", &n);
            Node *start = str;
            while (--n) {
                start = start->prev;
            }
            while (start != NULL) {
                putchar(start->c);
                start = start->next;
            }
            putchar('\n');
        }
        else {
            for (char c = string[0]; c != '\0'; c = *(++string)) {
                if (c == 'm') {
                    if (last_lower == NULL) {
                        continue;
                    }
                    Node *temp = last_lower;
                    last_lower->prev->next = last_lower->next;
                    if (str == last_lower) {
                        str = last_lower->prev;
                    }
                    if (last_lower->next != NULL) {
                        last_lower->next->prev = last_lower->prev;
                    }
                    last_lower = last_lower->last_same;
                    free(temp);
                }
                else if (c == 'M') {
                    if (last_upper == NULL) {
                        continue;
                    }
                    Node *temp = last_upper;
                    last_upper->prev->next = last_upper->next;
                    if (str == last_upper) {
                        str = last_upper->prev;
                    }
                    if (last_upper->next != NULL) {
                        last_upper->next->prev = last_upper->prev;
                    }
                    last_upper = last_upper->last_same;
                    free(temp);
                }
                else {
                    Node *new = malloc(sizeof(Node));
                    new->c = c;
                    new->prev = str;
                    str->next = new;
                    new->next = NULL;
                    if ('a' <= c && c <= 'z') {
                        new->last_same = last_lower;
                        last_lower = new;
                    }
                    else {
                        new->last_same = last_upper;
                        last_upper = new;
                    }
                    str = new;
                }
            }
        }
    }
    return 0;
}