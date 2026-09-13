#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node;

void createNode(Node **head){
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL){
        printf("Memory Allocation Failed. . . .");
        return;
    }
    printf("\nEnter Data : ");
    scanf("%d",&(temp->data));
    temp->link = NULL;
    *head = temp;
}

void addAtEnd(Node **head){
    Node *temp,*r;
    temp = *head;
    r = (Node *)malloc(sizeof(Node));
    while (temp->link!=NULL)
    {
        temp = temp->link;
    }
    printf("\nEnter Data:");
    scanf("%d",&(r->data));
    r->link = NULL;
    temp->link = r;

}

void display(Node **head){
    Node *temp;
    printf("\n");
    temp = *head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->link;
    }
    printf("\b\b  ");
}

void delAtLast(Node **head){
    Node *temp,*next;
    temp = *head;
    while(temp->link->link!=NULL){
        temp = temp->link;
    }
    next = temp->link;
    temp->link = NULL;
    free(next);
}

void delAtPos(Node **head){
    Node *temp,*next;
    temp = *head;
    int i,loc;
    printf("\nEnter Del Location : ");
    scanf("%d",&loc);

    if(loc == 1 || loc == 0){
        *head = temp->link;
        free(temp);
        return;
    }

    for(i=1;i<loc-1 && temp->link!=NULL;i++){
        temp = temp->link;
    }
    next = temp->link;
    temp->link = next->link;
    free(next);
}

void InsertAtPos(Node **head){
    Node *temp;
    Node *r;
    int i,loc;
    r = (Node *)malloc(sizeof(Node));
    temp = *head;
    printf("\nEnter position to be entered : ");
    scanf("%d",&loc);
    printf("\nEnter Data to be inserted : " );
    scanf("%d",&(r->data));

    if(loc==0||loc==1){
        r->link = *head;
        *head = r;
        return;
    }    

    for(i=1;i<loc-1 && temp != NULL;i++){
        temp = temp->link;
    }
    r->link = temp->link;
    temp->link = r;
}

void freeMem(Node **head){
    Node *temp,*prev;
    temp = *head;
    while(temp != NULL){
        prev = temp;
        temp = temp->link;
        free(prev);
    }
}

int main(){
    Node *head = NULL;
    char a;

    createNode(&head);
    display(&head);
    do{
    addAtEnd(&head);
    display(&head);
    
    printf("\nDo you want to continue?(Y/N)");
    scanf(" %c",&a);
    }while (a == 'y' || a == 'Y' );  
    InsertAtPos(&head);
    display(&head);
    delAtLast(&head);
    display(&head);
    delAtPos(&head);
    display(&head);
    freeMem(&head);
    return 0;
}