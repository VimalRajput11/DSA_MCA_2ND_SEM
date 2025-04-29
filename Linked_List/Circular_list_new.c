#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

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
    if (pos <= 1)
    {
        *headref = newnode;
        newnode->next = newnode;
    }
    else
    {
        struct node *temp = *headref;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp->next == *headref)
            {
                break;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
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
    if (pos == 1)
    {
        while (temp->next != *headref)
        {
            temp = temp->next;
        }
        struct node *ptr = *headref;
        temp->next = (*headref)->next;
        *headref = (*headref)->next;
        free(ptr);
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp->next == *headref)
            {
                printf("Position out of range.\n");
                return;
            }
        }
        struct node *ptr = temp->next;
        temp->next = temp->next->next;
        free(ptr);
    }
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

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

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
    if (pos <= 1)
    {
        *headref = newnode;
        newnode->next = newnode;
    }
    else
    {
        struct node *temp = *headref;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp->next == *headref)
            {
                break;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
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
    if (pos == 1)
    {
        while (temp->next != *headref)
        {
            temp = temp->next;
        }
        struct node *ptr = *headref;
        temp->next = (*headref)->next;
        *headref = (*headref)->next;
        free(ptr);
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp->next == *headref)
            {
                printf("Position out of range.\n");
                return;
            }
        }
        struct node *ptr = temp->next;
        temp->next = temp->next->next;
        free(ptr);
    }
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