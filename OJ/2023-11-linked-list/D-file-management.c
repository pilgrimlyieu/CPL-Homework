#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct File {
    char name[12];
    int files;
    struct File *father;
    struct File *subs[2];
} File;

File *root;

void FileInit(File* file, File* father, char* name) {
    strcpy(file->name, name);
    file->files = 1;
    file->father = father;
    file->subs[0] = NULL, file->subs[1] = NULL;
    if (file->father->subs[0] != NULL) {
        file->father->subs[1] = file;
    }
    else {
        file->father->subs[0] = file;
    }
    File *temp = father;
    while (temp != NULL) {
        temp->files++;
        temp = temp->father;
    }
}

File* Search(File* from, char* father) {
    if (from == NULL) {
        return NULL;
    }
    else if (strcmp(from->name, father) == 0) {
        return from;
    }
    for (int i = 0; i < 2; i++) {
        if (from->subs[i] != NULL) {
            File *file = Search(from->subs[i], father);
            if (file != NULL) {
                return file;
            }
        }
    }
    return NULL;
}

void Remove(char* name) {
    File *file = Search(root, name);
    File *temp = file->father;
    while (temp != NULL) {
        temp->files -= file->files;
        temp = temp->father;
    }
    for (int i = 0; i < 2; i++) {
        if (file->father->subs[i] == file) {
            file->father->subs[i] = NULL;
        }
    }
    free(file);
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);
    root = malloc(sizeof(File));
    root->files = 1;
    root->father = NULL;
    root->subs[0] = NULL, root->subs[1] = NULL;
    strcpy(root->name, "~~~");
    while (n--) {
        char file[12], father[12];
        scanf("%s %s", file, father);
        File *new = malloc(sizeof(File));
        FileInit(new, Search(root, father), file);
    }
    while (q--) {
        char mode[8], name[12];
        scanf("%s %s", mode, name);
        if (strcmp(mode, "query") == 0) {
            printf("%d\n", Search(root, name)->files);
        }
        else if (strcmp(mode, "remove") == 0) {
            Remove(name);
        }
    }
    return 0;
}