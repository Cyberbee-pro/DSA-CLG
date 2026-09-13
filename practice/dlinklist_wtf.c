#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>




typedef struct node{
int data;
struct node *prev;
struct node *next;
}Node;


#define AllocateMem1 (Node *)calloc(1,sizeof(Node))


void createList(Node **head)
{
    Node *temp;
    int data;
    temp = AllocateMem1;
    printf("\nEnter Data :");
    scanf("%d",&data);
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    *head = temp;
    printf("List Creation Success!!");

}

void InsertAtEnd(Node **head, Node **tail)
{
    Node *temp,*pre;
    int data;
    char a;
    pre = *head;
    do{
    printf("\nEnter Data :");
    scanf("%d",&data);
    temp = AllocateMem1;
    pre->next = temp;
    temp->data = data;
    temp->prev = pre;
    temp->next = NULL;

    pre = temp;

    fflush(stdin);

    printf("Do you want to continue?(Y/N)");
    scanf("%c",&a);
    }while (a == 'y' || a == 'Y' );

    if(temp->next == NULL && temp->prev != NULL){
        *tail = temp;
    }
    
    printf("Insertion Success!!");

}


void delBeg(Node **head){
    Node *temp = *head,*r;
    r = temp->next;
    r->prev = NULL;
    *head = r;
    free(temp);
    printf("\nDel At Beg success!!");
}



void travarseForward(Node **head)
{
    Node *temp;
    temp = *head;
    printf("\n");
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
}


void travarseBackward(Node **tail)
{
    Node *temp;
    temp = *tail;
    printf("\n");
    printf("NULL");
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->prev;
        }
        
}



void main()
{
    Node *Head = NULL;
    Node *tail = NULL;
    char a;
    int opt;


    do{
        printf("\nMenu\n");
        printf("\n1>CreateList\t2>Insert At End\n3>Del At Beg\t4>Traverse Forward\t5>Traverse Backward\t0>EXIT\n");
        printf("\nEnter Option:");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1: createList(&Head);
                break;
        case 2: InsertAtEnd(&Head,&tail);
                break;
        case 3: delBeg(&Head);
                break;
        case 4: travarseForward(&Head);
                break;
        case 5: travarseBackward(&tail);
                break;
        case 0: exit(0);
                break;
        default:printf("\nOPTION OUT OF BOUNDS");
            break;
        }

    fflush(stdin);

    printf("\nDo you want to continue?(Y/N)");
    scanf("%c",&a);
    }while (a == 'y' || a == 'Y' );

}
