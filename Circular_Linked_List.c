
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*tail=NULL;

void insert_Node(struct node **tail, int element, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (*tail == NULL) {
        *tail = newnode;
        newnode->next = newnode;
    } else {
        struct node *curr = *tail;
        while (curr->data != element) {
            curr = curr->next;
        }
        struct node *temp = curr->next;
        newnode->next = temp;
        curr->next = newnode;
    }
}

void display(struct node *tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = tail->next;
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

int main(){
    int choice, data, element;
    while (1) {
        printf("1. Insertion\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert_Node(&tail, element, data);
                break;
            case 2:
                display(tail);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}


