#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;

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

void insert_at_pos(struct node **headref, int data, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (pos<=1)
    {
        newnode->next = *headref;
        *headref = newnode;
        return;
    }
    struct node *temp = *headref;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void del_at_pos(struct node **headref, int pos)
{
    if (*headref == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    if (pos == 1)
    {
        *headref = (*headref)->next;
        free(temp);
        return;
    }
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        if (temp != NULL && temp->next == NULL) 
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
        else
        {
            printf("Position out of bounds.\n");
        }
        return;
    }
    struct node *ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);
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

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Display\n5.Del_at_beg\n4.Exit\n5.Del_at_beg\n6.Del_at_End\n7.Insert_at_Postion\n8.Delete_at_pos\n9.Count_Nodes\n10.Reverse_Linked-List\nEnter your choice: ");
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
            display(head);
            break;
        case 4:
            exit(1);
        case 5:
            del_at_beg(&head);
            break;
        case 6:
            del_at_end(&head);
            break;
        case 7:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position: ");
            int pos;
            scanf("%d", &pos);
            insert_at_pos(&head, data, pos);
            break;
        case 8:
            printf("Enter position to delete: ");
            int pos_del;
            scanf("%d", &pos_del);
            del_at_pos(&head, pos_del);
            break;
            case 9:
            Count_Nodes(head);
            break;
        case 10:
            reverse_Linked_List(&head);
            printf("Reversed linked list: ");
            display(head);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
