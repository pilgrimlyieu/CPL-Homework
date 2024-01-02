#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id, len;
    struct Node *next;
} Node;

int size2(int n) {
    int s = 0, i = 1;
    while (i < n) {
        s += 1;
        i *= 2;
    }
    return s;
}

void split(Node *mem) {
    Node *new = malloc(sizeof(Node));
    new->id = 0;
    new->len = --mem->len;
    new->next = mem->next;
    mem->next = new;
}

int main(void) {
    int n, q, num = 1;
    scanf("%d %d", &n, &q);
    Node *mem = malloc(sizeof(Node));
    mem->id = 0;
    mem->len = n;
    mem->next = NULL;
    while (q--) {
        getchar();
        if (getchar() == 'Q') {
            Node *query = mem;
            printf("%d\n", num);
            while (query) {
                printf("%d ", query->id);
                query = query->next;
            }
            putchar('\n');
        }
        else {
            int id, len;
            scanf("%d %d", &id, &len);
            len = size2(len);
            while (1) {
                Node *buddy = mem;
                while (buddy) {
                    if (buddy->id == 0 && buddy->len == len) {
                        buddy->id = id;
                        goto finish;
                    }
                    buddy = buddy->next;
                }
                buddy = mem;
                while (buddy) {
                    if (buddy->id == 0 && buddy->len > len) {
                        split(buddy);
                        num++;
                        break;
                    }
                    buddy = buddy->next;
                }
            }
            finish:
        }
    }
}