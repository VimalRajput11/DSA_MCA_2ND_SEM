#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    char val;
    struct node *next;
    struct node *prev;
} *head = NULL, *head1 = NULL;

void Linked_List(struct node **headref, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->val = '\0';
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*headref == NULL)
    {
        *headref = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        struct node *temp = *headref;
        while (temp->next != *headref)
        {
            temp = temp->next;
        }
        newnode->next = *headref;
        temp->next = newnode;
        newnode->prev = temp;
        (*headref)->prev = newnode;
    }
}

void char_Linked_List(struct node **headref, char data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->data = 0;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*headref == NULL)
    {
        *headref = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        struct node *temp = *headref;
        while (temp->next != *headref)
        {
            temp = temp->next;
        }
        newnode->next = *headref;
        temp->next = newnode;
        newnode->prev = temp;
        (*headref)->prev = newnode;
    }
}


void new_List(struct node *headA, struct node *headB, struct node **merged)
{
    if (!headA && !headB) return;
    struct node *temp = headA, *ptr = headB;
    int x = 0;
    int y=0;
    do {
        if (!x) {
            Linked_List(merged, temp->data);
            temp = temp->next;
            if (temp == headA) x = 1;
        }
        if (!y) {
            char_Linked_List(merged, ptr->val);
            ptr = ptr->next;
            if (ptr == headB) y = 1;
        }
    } while (!x || !y);
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    do
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void char_display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    do
    {     
        printf("%c --> ", temp->val);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void displayMerged(struct node *head)
{
    if (head == NULL)
    {
        printf("Merged list is empty.\n");
        return;
    }
    struct node *temp = head;
    do
    {
        if (temp->val != '\0')
            printf("%c --> ", temp->val);
        else
            printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}



int main()
{
    struct node *merged = NULL;
    Linked_List(&head, 1);
    Linked_List(&head, 2);
    Linked_List(&head, 3);
    Linked_List(&head, 4);
    Linked_List(&head, 5);
    Linked_List(&head, 6);
    display(head);
    char_Linked_List(&head1, 'a');
    char_Linked_List(&head1, 'b');
    char_Linked_List(&head1, 'c');
    char_Linked_List(&head1, 'd');
    char_Linked_List(&head1, 'e');
    char_Linked_List(&head1, 'f');
    char_display(head1);
    new_List(head, head1, &merged);
    displayMerged(merged);

    return 0;
}