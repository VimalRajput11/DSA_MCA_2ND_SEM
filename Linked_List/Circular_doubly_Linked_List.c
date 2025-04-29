// Implementation of Circular Doubly Linked List in C insertion at beginning, display
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

void insert_at_beginning(struct node **headref, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
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
        newnode->prev = *headref;
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

void insert_at_position(struct node **headref, int data, int pos)
{
    struct node *newnode;
    
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    if (*headref == NULL)
    {
        *headref = newnode;
        newnode->prev = newnode;
        newnode->next = newnode;
    }
    if (pos <= 1)
    {
        struct node *temp = *headref;
        while (temp->next != *headref)
        {
            temp = temp->next;
        }
        newnode->next = *headref;
        temp->next = newnode;
        newnode->prev = *headref;
        (*headref)->prev = newnode;
        *headref = newnode;
    }
    else
    {
        struct node *temp = *headref;

        for (int i = 1; i < pos - 1 && temp != *headref; i++)
        {
            temp = temp->next;
            if(temp==*headref){
               newnode->next = *headref;
                temp->next = newnode;
                newnode->prev = temp;
                (*headref)->prev = newnode;
            }
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void delete_at_beginning(struct node **headref) {
    if (*headref == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    if ((*headref)->next == *headref) {
        *headref = NULL;
    } else {
        struct node *ptr = (*headref)->prev;
        *headref = (*headref)->next;
        (*headref)->prev = ptr;
        ptr->next = *headref;
    }
    free(temp);
}

void delete_at_end(struct node **headref) {
    if (*headref == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    if ((*headref)->next == *headref) {
        *headref = NULL;
    } else {
        struct node *ptr = (*headref)->prev;
        ptr->prev->next = *headref;
        (*headref)->prev = ptr->prev;
        temp = ptr;
    }
    free(temp);
}

void delete_at_position(struct node **headref, int pos) {
    if (*headref == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *headref;
    if (pos <= 1) {
        struct node *ptr = *headref;
        if ((*headref)->next == *headref) {
            *headref = NULL;
        } else {
            struct node *last = (*headref)->prev;
            *headref = (*headref)->next;
            (*headref)->prev = last;
            last->next = *headref;
        }
        free(ptr);
        return; 
    }
    for (int i = 1; i < pos && temp->next != *headref; i++) {
        temp = temp->next;
    }
    if (temp->next == *headref && temp != *headref) {
        struct node *ptr = temp;
        struct node *last = temp->prev;
        last->next = *headref;
        (*headref)->prev = last;
        free(ptr);
        return;
    }
    struct node *ptr = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(ptr);
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
    int choice, data,pos;
    while (1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
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
            
            printf("Enter the data to insert:");
            scanf("%d", &data);
            printf("Enter the Position:");
            scanf("%d", &pos);
            insert_at_position(&head, data, pos);
            break;
        case 4:
            delete_at_beginning(&head);
            break;
        case 5:
            delete_at_end(&head);
            break;
        case 6:
            printf("Enter the Position:");
            scanf("%d", &pos);
            delete_at_position(&head, pos);
            break;
        case 7:
            printf("The Linked List is\n");
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
