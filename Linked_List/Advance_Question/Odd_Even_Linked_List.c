//Implementation of odd even linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void Linked_List(struct Node **headref, int newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;

    if (*headref == NULL)
    {
        *headref = newnode;
    }
    else
    {
        struct Node *temp = *headref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct Node* Odd_Even_Linked_List(struct Node **headref)
{
    if (*headref == NULL || (*headref)->next == NULL)
        return *headref;

    struct Node *odd = *headref;
    struct Node *even = (*headref)->next;
    struct Node *evenHead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead; 
    return *headref;
}

void display(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    Linked_List(&head, 1);
    Linked_List(&head, 2);
    Linked_List(&head, 3);
    Linked_List(&head, 4);
    Linked_List(&head, 5);
    Linked_List(&head, 6);
    Linked_List(&head, 7);
    Linked_List(&head, 8);
    Linked_List(&head, 9);
    Linked_List(&head, 10);

    printf("Original List: ");
    display(head);

    struct Node*oddevenhead=Odd_Even_Linked_List(&head);

    printf("Odd Even List: ");
    display(oddevenhead);

    return 0;
}