#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int content;
    struct Node *next;
} Node;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    Node **stacks = malloc(sizeof(Node *) * (n + 1));
    for(int i = 1; i <= n; i++) {
        stacks[i] = malloc(sizeof(Node));
        stacks[i]->content = i;
        stacks[i]->next = NULL;
    }
    while(m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        Node *temp = stacks[x];
        while (temp != NULL) {
            stacks[x] = temp->next;
            temp->next = stacks[y];
            stacks[y] = temp;
            temp = stacks[x];
        }
    }
    for (int i = 1; i <= n; i++) {
        Node *temp = stacks[i];
        if (temp == NULL) {
            printf("0\n");
            continue;
        }
        int *arr = malloc(sizeof(int) * n);
        int len = 0;
        while (temp != NULL) {
            arr[len++] = temp->content;
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
        for (int j = len - 1; j >= 0; j--) {
            printf("%d ", arr[j]);
        }
        printf("\n");
        free(arr);
    }
    free(stacks);
    return 0;
}