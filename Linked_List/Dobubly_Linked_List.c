// Doubly Linked List Implementation in C
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;


void insert_at_beginning(struct node **headref, int data);
void insert_at_end(struct node **headref, int data);
void insert_at_position(struct node **headref, int data, int pos);
void deletion_at_beginning(struct node **headref);
void deletion_at_end(struct node **headref);
void deletion_at_position(struct node **headref, int pos);
void display(struct node *temp);


int main()
{
    int choice, data, pos;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insert_at_beginning(&head, data);
            break;
        case 2:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insert_at_end(&head, data);
            break;
        case 3:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insert_at_position(&head, data, pos);
            break;
        case 4:
            deletion_at_beginning(&head);
            break;
        case 5:
            deletion_at_end(&head);
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            deletion_at_position(&head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

// Function definitions
void insert_at_beginning(struct node **headref, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*headref == NULL)
    {
        *headref = newnode;
    }
    else
    {
        newnode->next = *headref;
        (*headref)->prev = newnode;  
        *headref = newnode;
    }
}

void insert_at_end(struct node **headref, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*headref == NULL)
    {
        *headref = newnode;
    }
    else
    {
        struct node *temp = *headref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insert_at_position(struct node **headref, int data, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;    
    newnode->prev = NULL;

    if (*headref == NULL)
    {
        *headref = newnode;
    }

    if (pos <= 1)
    {
        printf("Position is less than or equal to 1. Inserting at the head.\n");
        newnode->next = *headref;
        (*headref)->prev = newnode;
        *headref = newnode;
    }
    else
    {
        struct node *temp = *headref;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Position is out of bounds. Inserting at the end.\n");
            temp->next = newnode;
            newnode->prev = temp;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deletion_at_beginning(struct node **headref)
{
    if (*headref == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    *headref = (*headref)->next;
    (*headref)->prev = NULL;
    free(temp);
}

void deletion_at_end(struct node **headref)
{
    if (*headref == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deletion_at_position(struct node **headref, int pos)
{
    if (*headref == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    if (pos <= 1)
    {
        *headref = (*headref)->next;
        (*headref)->prev = NULL;
        free(temp);
        return;
    }
    for (int i = 1; i < pos && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Position out of range. Deleting at the end.\n");
        temp->prev->next = NULL;
        free(temp);
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void display(struct node *temp)
{
    printf("List elements are: ");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}