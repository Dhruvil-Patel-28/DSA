#include<stdio.h>
#include<stdlib.h>
//-----------------------------------------------------
struct node
{
    struct node *prev;
    int Coefficient;
    int Degree;
    struct node *next;
};
//-----------------------------------------------------
struct node *Create_Node_C()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    
    tmp->Coefficient = 0;
    tmp->Degree = 0;

    tmp->prev = NULL;
    tmp->next = NULL;
    return tmp;
}
//-----------------------------------------------------
struct node *Create_Node()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Coefficient\n");
    scanf("%d",&tmp->Coefficient);
    printf("Enter Degree\n");
    scanf("%d",&tmp->Degree);
    
    tmp->prev = NULL;
    tmp->next = NULL;
    return tmp;
}
//-----------------------------------------------------
struct node *CreateLL(int n)
{
    struct node *head = Create_Node();
    struct node *tmp = head;
    struct node *NewNode;

    for(int i=1;i<n;i++)
    {
        NewNode = Create_Node();
        tmp->next = NewNode;
        NewNode->prev = tmp;
        tmp = tmp->next;
    }
    return head;
}
//-----------------------------------------------------
int main()
{
    int n1,n2;
    int b;
    int d;
    struct node *head1;
    struct node *tmp;
    struct node *t;
    
    printf("Enter the Number of Coefficients in the Polynomial 1\n");
    scanf("%d",&n1);
    
    head1 = CreateLL(n1);
    tmp = head1;
    t = head1;

    printf("Enter the Number of Coefficients in the Polynomial 2\n");
    scanf("%d",&n2);

    while(t!=NULL)
    {
        printf("Enter Coefficient\n");
        scanf("%d",&b);
        printf("Enter Degree\n");
        scanf("%d",&d);

        if(d == tmp->Degree)
        {
            tmp->Coefficient += b;
            tmp = tmp->next;
            t = t->next;
        }
        else if(d > tmp->Degree)
        {
            tmp->prev = Create_Node_C();
            t = t->prev;
            t->Coefficient = b;
            t->Degree = d;
            t->next = tmp;
            tmp = tmp->next;
            t = tmp;
        }
        else
        {
            tmp = tmp->next;
            t = tmp;
            if(d == tmp->Degree)
        {
            tmp->Coefficient += b;
            tmp = tmp->next;
            t = t->next;
        }
        else if(d > tmp->Degree)
        {
            tmp->prev = Create_Node_C();
            t = t->prev;
            t->Coefficient = b;
            t->Degree = d;
            t->next = tmp;
            tmp = tmp->next;
            t = tmp;
        }
        }
    }
    tmp = head1;
    while(tmp != NULL)
    {
        printf("Degree : %d\t Coefficient : %d\t Address : %d\n",tmp->Degree,tmp->Coefficient,&tmp->next);
        tmp = tmp->next;
    }

}