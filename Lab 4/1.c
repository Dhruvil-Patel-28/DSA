#include <stdio.h>
#include <stdlib.h>
//-------------------------------------------------------------------------
struct Node 
{
    int digit;
    struct Node* next;
};
//-------------------------------------------------------------------------
struct Node* createNode(int digit) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}
//-------------------------------------------------------------------------
struct Node* insertAtHead(struct Node* head, int digit) 
{
    struct Node* newNode = createNode(digit);
    newNode->next = head;
    return newNode;
}
//-------------------------------------------------------------------------
struct Node* addLinkedLists(struct Node* l1, struct Node* l2) 
{
    struct Node* result = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) 
    {
        int sum = carry;
        if (l1 != NULL) 
        {
            sum += l1->digit;
            l1 = l1->next;
        }
        if (l2 != NULL) 
        {
            sum += l2->digit;
            l2 = l2->next;
        }

        carry = sum / 10;

        result = insertAtHead(result, sum % 10);
    }

    if (carry > 0) 
    {
        result = insertAtHead(result, carry);
    }

    return result;
}
//-------------------------------------------------------------------------
void printLinkedList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d", head->digit);
        head = head->next;
    }
    printf("\n");
}
//-------------------------------------------------------------------------
struct Node* reverseLinkedList(struct Node* head) 
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}
//-------------------------------------------------------------------------
struct Node* appendDigit(struct Node* head, int digit) 
{
    struct Node* newNode = createNode(digit);
   
    if (head == NULL) 
    {
        return newNode;
    }
    
    struct Node* temp = head;
    
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    
    return head;
}
//-------------------------------------------------------------------------
int main() 
{
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    struct Node* result = NULL;

    num1 = appendDigit(num1, 7);
    num1 = appendDigit(num1, 6);
    num1 = appendDigit(num1, 4);
    num1 = appendDigit(num1, 3);
    num1 = appendDigit(num1, 4);
    num1 = appendDigit(num1, 5);

    num2 = appendDigit(num2, 5);
    num2 = appendDigit(num2, 1);
    num2 = appendDigit(num2, 3);
    num2 = appendDigit(num2, 8);
    num2 = appendDigit(num2, 4);
    
    result = addLinkedLists(num1, num2);

    printf("Number 1: ");
    printLinkedList(reverseLinkedList(num1));
    printf("Number 2: ");
    printLinkedList(reverseLinkedList(num2));

    

    printf("Result: ");
    printLinkedList(result); 

    return 0;
}
