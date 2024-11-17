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
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->Coefficient = 0;
    tmp->Degree = 0;
    tmp->prev = NULL;
    tmp->next = NULL;
    return tmp;
}

//-----------------------------------------------------
struct node *Create_Node() 
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Coefficient: \n");
    scanf("%d", &tmp->Coefficient);
    printf("Enter Degree: \n");
    scanf("%d", &tmp->Degree);
    tmp->prev = NULL;
    tmp->next = NULL;
    return tmp;
}

//-----------------------------------------------------
struct node *CreateLL(int n) 
{
    struct node *head = Create_Node();
    struct node *tmp = head;

    for (int i = 1; i < n; i++) 
    {
        struct node *NewNode = Create_Node();
        tmp->next = NewNode;
        NewNode->prev = tmp;
        tmp = tmp->next;
    }
    return head;
}

//-----------------------------------------------------
int main() 
{
    int n1, n2;
    struct node *head1, *tmp, *t;

    printf("Enter the Number of Coefficients in Polynomial 1: \n");
    scanf("%d", &n1);

    head1 = CreateLL(n1);
    tmp = head1;

    printf("Enter the Number of Coefficients in Polynomial 2: \n");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) 
    {
        int b, d;
        printf("Enter Coefficient: \n");
        scanf("%d", &b);
        printf("Enter Degree: \n");
        scanf("%d", &d);

        while (tmp != NULL && tmp->Degree > d) 
        {
            tmp = tmp->next;
        }

        if (tmp != NULL && tmp->Degree == d) 
        {
            tmp->Coefficient += b;
        } else {
            struct node *newNode = Create_Node_C();
            newNode->Coefficient = b;
            newNode->Degree = d;

            if (tmp == NULL) 
            {  
                tmp = head1;
                while (tmp->next != NULL) 
                {
                    tmp = tmp->next;
                }
                tmp->next = newNode;
                newNode->prev = tmp;
            } else if (tmp->prev == NULL) 
            {  
                newNode->next = head1;
                head1->prev = newNode;
                head1 = newNode;
            } else 
            {  
                newNode->next = tmp;
                newNode->prev = tmp->prev;
                tmp->prev->next = newNode;
                tmp->prev = newNode;
            }
        }
    }

    tmp = head1;
    printf("Polynomial after Addition:\n");
    while (tmp != NULL) 
    {
        printf("Degree: %d\t Coefficient: %d\t Address: %d\n", tmp->Degree, tmp->Coefficient, &tmp);
        tmp = tmp->next;
    }

    return 0;
}
