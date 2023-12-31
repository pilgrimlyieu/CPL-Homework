#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char s[25];
    struct Node *next;
} Node;

Node **nodes;

int main(void) {
    int n;
    scanf("%d", &n);
    nodes = malloc(sizeof(Node *) * (n + 1));
    for (int i = 1; i <= n; i++) {
        nodes[i] = malloc(sizeof(Node));
    }
    for (int i = 1; i <= n; i++) {
        int next;
        scanf("%s %d", nodes[i]->s, &next);
        if (1 <= next && next <= n) {
            nodes[i]->next = nodes[next];
        }
        else {
            nodes[i]->next = NULL;
        }
    }
    int cycle = 0;
    Node *c, *d = nodes[1];
    while (!cycle) {
        Node *p = nodes[1], *q = nodes[1];
        while (p && q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                cycle = 1;
                c = p;
                break;
            }
        }
        break;
    }
    if (cycle) {
        while(c != d) {
            c = c->next;
            d = d->next;
        }
        printf("%s\n", c->s);
    }
    else {
        puts("-1");
    }
}