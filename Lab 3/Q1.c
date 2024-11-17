#include<stdio.h>
#include<stdlib.h>
//-------------------------------------------------------------------
struct node{
    int data;
    int priority;
    struct node* next;
};
//-------------------------------------------------------------------
struct node* usePriority(struct node *head,int Data,int Priority){
    struct node *new = malloc(sizeof(struct node));

    new->data = Data;
    new->priority = Priority;
    new->next = NULL;

    if(head==NULL || head->priority >= Priority){
        new->next = head;
        head = new;
        return(head);
    }

    struct node* temp=head;
    while(temp->next!=NULL && temp->next->priority < Priority){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;

    return(head);
}
//-------------------------------------------------------------------
struct node* useData(struct node *head,int Data){
    struct node *new = malloc(sizeof(struct node));

    new->data = Data;
    new->priority = 0;
    new->next = NULL;

    if(head==NULL || head->data >= Data){
        new->next = head;
        head = new;
        return(head);
    }

    struct node* temp=head;
    while(temp->next!=NULL && temp->next->data < Data){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;

    return(head);
}
//-------------------------------------------------------------------
void printlist(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("data:- %d,priority:- %d  \n",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("\n");
}
//-------------------------------------------------------------------
int main(){
    struct node* head = NULL;


    // head = usePriority(head, 5, 3);
    // head = usePriority(head, 2, 1);
    // head = usePriority(head, 10, -1);
    // head = usePriority(head, 8, 5);
    // printlist(head);


    head = useData(head, 7);
    head = useData(head, 8);
    head = useData(head, 9);
    head = useData(head, 10);
    printlist(head);
}