#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    struct Node *link;
} Node;

Node *urgent_head = NULL;
Node *regular_head = NULL;

void arrive(char *name, char *priority) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->link = NULL;

    if (strcmp(priority, "URGENT") == 0) {
        if (urgent_head == NULL) {
            urgent_head = new_node;
        } else {
            Node *temp = urgent_head;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = new_node;
        }
    } else {
        if (regular_head == NULL) {
            regular_head = new_node;
        } else {
            Node *temp = regular_head;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = new_node;
        }
    }
}

void serve() {
    if (urgent_head != NULL) {
        Node *temp = urgent_head;
        printf("SERVE -> %s\n", temp->name);
        urgent_head = urgent_head->link;
        free(temp);
    } else if (regular_head != NULL) {
        Node *temp = regular_head;
        printf("SERVE -> %s\n", temp->name);
        regular_head = regular_head->link;
        free(temp);
    } else {
        printf("SERVE -> None (Queue is empty)\n");
    }
}

void cancel(char *name) {
    Node *temp = urgent_head, *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                urgent_head = temp->link;
            } else {
                prev->link = temp->link;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->link;
    }

    temp = regular_head;
    prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                regular_head = temp->link;
            } else {
                prev->link = temp->link;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->link;
    }
}

void upgrade(char *name) {
    Node *temp = regular_head, *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                regular_head = temp->link;
            } else {
                prev->link = temp->link;
            }
            temp->link = NULL;

            if (urgent_head == NULL) {
                urgent_head = temp;
            } else {
                Node *u_temp = urgent_head;
                while (u_temp->link != NULL) {
                    u_temp = u_temp->link;
                }
                u_temp->link = temp;
            }
            return;
        }
        prev = temp;
        temp = temp->link;
    }
}

void list_queue() {
    printf("LIST -> URGENT:[");
    Node *temp = urgent_head;
    int first = 1;
    while (temp != NULL) {
        if (!first) printf(", ");
        printf("%s", temp->name);
        first = 0;
        temp = temp->link;
    }
    printf("] REGULAR:[");
    
    temp = regular_head;
    first = 1;
    while (temp != NULL) {
        if (!first) printf(", ");
        printf("%s", temp->name);
        first = 0;
        temp = temp->link;
    }
    printf("]\n");
}

int main() {
    char op[20], name[50], priority[20];
    int n;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "ARRIVE") == 0) {
            scanf("%s %s", name, priority);
            arrive(name, priority);
        } else if (strcmp(op, "SERVE") == 0) {
            serve();
        } else if (strcmp(op, "CANCEL") == 0) {
            scanf("%s", name);
            cancel(name);
        } else if (strcmp(op, "UPGRADE") == 0) {
            scanf("%s", name);
            upgrade(name);
        } else if (strcmp(op, "LIST") == 0) {
            list_queue();
        }
    }

    return 0;
}
