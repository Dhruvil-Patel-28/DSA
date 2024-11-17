#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node
{
   int coef;
   int expo;
   struct node *next;
};

struct node *createlist(struct node *head)
{
   int choice = 1;
   printf("Enter data of Polynomial\n");
   while (choice == 1)
   {
      struct node *temp = (struct node *)malloc(sizeof(struct node));

      printf("Enter coefficient and exponent\n");
      scanf("%d %d", &temp->coef, &temp->expo);
      temp->next = NULL;

      if (head == NULL)
      {
         head = temp;
         head->next = NULL;
      }
      else
      {
         struct node *last;
         last = head;

         while (last->next!= NULL)
         {
            last = last->next;
         }
         last->next= temp;
      }
      printf("Enter '0' to finish the polynoial and '1' to continue\n");
      scanf("%d", &choice);
   }
   return head;
}
void printlist(struct node *head)
{
   struct node *temp = head;
   if (temp == NULL)
   {
      printf("list is empty");
   }
   else
   {
      while (temp != NULL)
      {
         printf("%dx^%d", temp->coef, temp->expo);

         temp = temp->next;
         if (temp != NULL)
            printf("+ ");
      }
      printf("\n");
   }
   return;
}
void freeList(struct node *head)
{
   struct node *temp;
   while (head != NULL)
   {
      temp = head;
      head = head->next;
      free(temp);
   }
}

int main()
{
   struct node *n1;
   struct node *n2;
   n1 = NULL;
   n2 = NULL;
   printf("Enter Polynomial 1\n");
   n1 = createlist(n1);

   printf("Enter Polynomial 2\n");
   n2 = createlist(n2);

   printf("Polynomial 1 is\n");
   printlist(n1);

   printf("Polynomial 2 is\n");
   printlist(n2);

   freeList(n1);
   freeList(n2);
}