#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;
void insert_beg(struct node **headref, int data);
void insert_at_end(struct node **headref, int data);
void insert_at_position(struct node **headref, int data, int pos);
void del_at_beg(struct node **headref);
void del_at_end(struct node **headref);
void del_at_pos(struct node **headref, int pos);
void Count_Nodes(struct node *temp);
void reverse_Linked_List(struct node **headref);
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
        printf("8. Count nodes\n");
        printf("9. Reverse linked list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert_beg(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert_at_end(&head, data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_at_position(&head, data, pos);
            break;
        case 4:
            del_at_beg(&head);
            break;
        case 5:
            del_at_end(&head);
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            del_at_pos(&head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            Count_Nodes(head);
            break;
        case 9:
            reverse_Linked_List(&head);
            printf("Reversed linked list: ");
            display(head);
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void insert_beg(struct node **headref, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *headref;
    *headref = newnode;
}

void insert_at_end(struct node **headref, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (*headref == NULL)
    {
        *headref = newnode;
        return;
    }
    struct node *temp = *headref;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
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
          temp = temp->next;

    if (temp->next == NULL)
        printf("Position is out of bounds. Inserting at the end.\n");

    newnode->next = temp->next;
    temp->next = newnode;
}

void del_at_beg(struct node **headref)
{
    if (*headref == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = *headref;
    *headref = (*headref)->next;
    free(temp);
}

void del_at_end(struct node **headref)
{
    if (*headref == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    if (temp->next == NULL)
    {
        free(temp);
        *headref = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void del_at_pos(struct node **headref, int pos)
{
    if (*headref == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 1)
    {
        printf("Position is less than or equal to 1. Deleting at the head.\n");
        struct node *temp = *headref;
        *headref = (*headref)->next;
        free(temp);
        return;
    }

    struct node *temp = *headref;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Position is out of bounds. Deleting at the end.\n");
        struct node *end_temp = *headref;
        while (end_temp->next->next != NULL)
        {
            end_temp = end_temp->next;
        }
        free(end_temp->next);
        end_temp->next = NULL;
        return;
    }

    struct node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

void Count_Nodes(struct node *temp)
{
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}

void reverse_Linked_List(struct node **headref)
{
    struct node *prev = NULL, *current = *headref, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headref = prev;
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