#include<stdio.h>
#include<stdlib.h>

struct nodeH
{
    struct nodeH *down;
    struct nodeH *right;
    struct nodeH *next;
};

struct nodeE
{
    int row;
    int col;
    int val;
    struct nodeH *down;
    struct nodeH *right;
};

int main()
{
    int n;
    int r,c;
    printf("Enter the Number of Rows\n");
    scanf("%d",&r);
    printf("Enter the Number of Columns\n");
    scanf("%d",&c);
    printf("Enter the Number of Non-Zero terms in the Sparse Matrix\n");
    scanf("%d",&n);

    

}