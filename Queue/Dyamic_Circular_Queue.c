#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


void enqueue(struct node **front, struct node **rear, int value);
void dequeue(struct node **front, struct node **rear);
void display(struct node *front);

int main(){
    struct node * front=NULL;
    struct node * rear=NULL;
    int choice,data;

    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the data to enqueue");
            scanf("%d",&data);
            enqueue(&front,&rear,data);
            break;
            case 2:
            dequeue(&front,&rear);
            break;
            case 3:
            display(front);
            break;
            case 4:
            printf("Exiting...\n");
            exit(0);
            default:
            printf("Invalid choice\n");

        }
    }
    return 0;
}

void enqueue(struct node **front, struct node **rear, int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (*front == NULL && *rear == NULL) {
        *front = newnode;
        *rear = newnode;
        newnode->next = *front;
    } else {
        (*rear)->next = newnode;
        (*rear) = newnode;
        (*rear)->next = *front;
    }
}

void dequeue(struct node **front, struct node **rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = *front;
    if (*front == *rear) {
        *front = NULL;
        *rear = NULL;
    } else {
        *front = (*front)->next;
        (*rear)->next = *front;
    }
    free(temp);
}

void display(struct node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}


