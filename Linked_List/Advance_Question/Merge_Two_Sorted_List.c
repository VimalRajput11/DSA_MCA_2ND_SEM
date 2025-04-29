// Implementation of merging two sorted linked lists
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void First_Linked_List(struct Node **headref, int newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = (*headref);
    (*headref) = newnode;
}
void Second_Linked_List(struct Node **headref1, int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = (*headref1);
    (*headref1) = newnode;
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
struct Node *merge(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node *result = NULL;
    if (head1->data <= head2->data)
    {
        result = head1;
        result->next = merge(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merge(head1, head2->next);
    }
    return result;
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *merged_list = NULL;

    First_Linked_List(&head1, 5);
    First_Linked_List(&head1, 3);
    First_Linked_List(&head1, 1);
    display(head1);
    Second_Linked_List(&head2, 6);
    Second_Linked_List(&head2, 4);
    Second_Linked_List(&head2, 2);
    display(head2);
    merged_list = merge(head1, head2);
    printf("Merged Linked List: \n");
    display(merged_list);

    return 0;
}