#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void insert_at_beginning(struct node **headref, int data);
void insert_at_end(struct node **headref, int data);
void deletion_at_beginning(struct node **headref);
void insert_at_position(struct node **headref, int data, int pos);
void deletion_at_end(struct node **headref);
void deletion_at_position(struct node **headref, int pos);
void display(struct node *head);


void insert_at_beginning(struct node **headref, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (*headref == NULL)
    {
        *headref = newnode;
        newnode->next = newnode;
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

        *headref = newnode;
    }
}

void insert_at_end(struct node **headref, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (*headref == NULL)
    {
        *headref = newnode;
        newnode->next = newnode;
    }
    else
    {
        struct node *temp = *headref;
        while (temp->next != *headref)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *headref;
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
    while (temp->next != *headref)
    {
        temp = temp->next;
    }
    struct node *ptr = *headref;
    temp->next = (*headref)->next;
    *headref = (*headref)->next;
    free(ptr);
}

void insert_at_position(struct node **headref, int data, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (pos <= 1 || *headref == NULL)
    {
        printf("Position is less than or equal to 1. Inserting at the head.\n");
        newnode->next = *headref;
        *headref = newnode;
        return;
    }

    struct node *temp = *headref;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Position is out of bounds. Inserting at the end.\n");
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletion_at_end(struct node **headref)
{
    if (*headref == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    while (temp->next->next != *headref)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = *headref;
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
        printf("Position is less than or equal to 1. Deleting at the head.\n");
        struct node *to_delete = *headref;
        while (temp->next != *headref)
        {
            temp = temp->next;
        }
        if (temp == *headref) // Only one node in the list
        {
            *headref = NULL;
        }
        else
        {
            temp->next = (*headref)->next;
            *headref = (*headref)->next;
        }
        free(to_delete);
        return;
    }

    struct node *prev = NULL;
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == *headref)
        {
            printf("Position out of range. Deleting at the end.\n");
            prev->next = *headref;
            free(temp);
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
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