#include <stdio.h>
#include <stdlib.h>

void Sort(int array[], int order[], int low, int high) {
    if (low >= high)
        return;
    int i = low - 1, j = high + 1, pivot = array[(low + high) / 2];
    while (i < j) {
        do {
            i++;
        } while (array[i] < pivot);
        do {
            j--;
        } while (array[j] > pivot);
        if (i < j) {
            int temp = array[i], temp_o = order[i];
            array[i] = array[j];
            array[j] = temp;
            order[i] = order[j];
            order[j] = temp_o;
        }
    }
    Sort(array, order, low, j);
    Sort(array, order, j + 1, high);
}

int main(void) {
    int n;
    scanf("%d", &n);
    char **teams = malloc(sizeof(teams) * n);
    int *attacks = malloc(sizeof(attacks) * n), *defences = malloc(sizeof(defences) * n), *organizations = malloc(sizeof(organizations) * n);
    for (int i = 0; i < n; i++)
        *(attacks + i) = *(defences + i) = *(organizations + i) = 0;
    for (int i = 0; i < n; i++) {
        *(teams + i) = malloc(sizeof(char) * 25);
        scanf("%s", *(teams + i));
        for (int j = 0; j < 11; j++) {
            char name[20];
            int attack, defence, organization;
            scanf("%s %d %d %d", name, &attack, &defence, &organization);
            *(attacks + i) += attack;
            *(defences + i) += defence;
            *(organizations + i) += organization;
        }
    }
    int order[n];
    for (int i = 0; i < n; i++)
        order[i] = i;
    Sort(attacks, order, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
        printf("%s ", teams[order[i]]);
    printf("\n");
    for (int i = 0; i < n; i++)
        order[i] = i;
    Sort(defences, order, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
        printf("%s ", teams[order[i]]);
    printf("\n");
    for (int i = 0; i < n; i++)
        order[i] = i;
    Sort(organizations, order, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
        printf("%s ", teams[order[i]]);
    return 0;
}