#include<stdio.h>
#include<stdlib.h>
//----------------------------------------------------------
struct node
{
    int Coefficient;
    int Degree;
    struct node *next;
};
//----------------------------------------------------------
struct node *Create_Node()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Coefficient\n");
    scanf("%d",&tmp->Coefficient);
    printf("Enter Degree\n");
    scanf("%d",&tmp->Degree);
    
    
    tmp->next = NULL;
    return tmp;
}
//----------------------------------------------------------
struct node *Create_Node_C()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    
    tmp->Coefficient = 0;
    tmp->Degree = 0;

    tmp->next = NULL;
    return tmp;
}
//---------------------------------------------------------------
struct node *CreateLL_C(int deg)
{
    struct node *head = Create_Node_C();
    struct node *tmp = head;
    struct node *NewNode;

    for(int i=1;i<6;i++)
    {
        NewNode = Create_Node_C();
        tmp->next = NewNode;
        tmp = tmp->next;
    }
    return head;
}
//---------------------------------------------------------------
struct node *CreateLL(int n)
{
    struct node *head = Create_Node();
    struct node *tmp = head;
    struct node *NewNode;

    for(int i=1;i<n;i++)
    {
        NewNode = Create_Node();
        tmp->next = NewNode;
        tmp = tmp->next;
    }
    return head;
}
//-----------------------------------------------------------------
int main()
{
    int n1,n2,n3;
    struct node *head1,*head2,*head3;
    
    printf("Enter the Number of Coefficients in the Polynomial 1\n");
    scanf("%d",&n1);
    printf("Enter the Number of Coefficients in the Polynomial 2\n");
    scanf("%d",&n2);

    int deg;
    if((head1->Degree)>=(head2->Degree))
    {
        deg = head1->Degree;
    }
    else
    {
        deg = head2->Degree;
    }
    
    printf("\n\n");
    head1 = CreateLL(n1);
    printf("\n\n");
    head2 = CreateLL(n2);
    printf("\n\n");
    head3 = CreateLL_C(deg);
    
    
    struct node *tmp1 = head1;
    struct node *tmp2 = head2;
    struct node *tmp3 = head3;

    while(tmp1 != NULL && tmp2 != NULL)
    {
        if(tmp1->Degree == tmp2->Degree)
        {
            tmp3->Degree = tmp1->Degree;
            tmp3->Coefficient = tmp1->Coefficient + tmp2->Coefficient;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            tmp3 = tmp3->next;
        }
        else if(tmp1->Degree > tmp2->Degree)
             {
                tmp3->Degree = tmp1->Degree;
                tmp3->Coefficient = tmp1->Coefficient;
                tmp1 = tmp1->next;
                tmp3 = tmp3->next;
             }
        else if(tmp1->Degree < tmp2->Degree)
        {
            tmp3->Degree = tmp2->Degree;
            tmp3->Coefficient = tmp2->Coefficient;
            tmp2 = tmp2->next;
            tmp3 = tmp3->next;
        }  
    }
    while(tmp1 != NULL)
    {
        tmp3->Degree = tmp1->Degree;
        tmp3->Coefficient = tmp1->Coefficient;
        tmp3 = tmp3->next;
        tmp1 = tmp1->next;
    }
    
    while(tmp2 != NULL)
    {
        tmp3->Degree = tmp2->Degree;
        tmp3->Coefficient = tmp2->Coefficient;
        tmp3 = tmp3->next;
        tmp2 = tmp2->next;
    }

    tmp1 = head1;
    tmp2 = head2;
    tmp3 = head3;

    printf("Polynomial 1 : \n");
    while(tmp1 != NULL)
    {
        printf("Degree : %d\t Coefficient : %d\t Address : %d\n",tmp1->Degree,tmp1->Coefficient,&tmp1->next);
        tmp1 = tmp1->next;
    }

    printf("Polynomial 2 : \n");
    while(tmp2 != NULL)
    {
        printf("Degree : %d\t Coefficient : %d\t Address : %d\n",tmp2->Degree,tmp2->Coefficient,&tmp2->next);
        tmp2 = tmp2->next;
    }
    printf("Polynomial 3 : \n");
    while(tmp3 != NULL)
    {
        printf("Degree : %d\t Coefficient : %d\t Address : %d\n",tmp3->Degree,tmp3->Coefficient,&tmp3->next);
        tmp3 = tmp3->next;
    }

    while (head1 != NULL) {
        tmp1 = head1;
        head1 = head1->next;
        free(tmp1);
    }

    while (head2 != NULL) {
        tmp2 = head2;
        head2 = head2->next;
        free(tmp2);
    }

    while (head3 != NULL) {
        tmp3 = head3;
        head3 = head3->next;
        free(tmp3);
    }

    return 0;

}