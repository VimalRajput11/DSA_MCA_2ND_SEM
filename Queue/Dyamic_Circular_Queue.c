#include <stdio.h>
#include<stdlib.h>

struct queue {
    int data;
    struct queue *next;
};


void enqueue(struct queue **frontref, struct queue **rearref, int value);
void dequeue(struct queue **frontref, struct queue **rearref);
void display(struct queue *front);

int main(){
    struct queue * front=NULL;
    struct queue * rear=NULL;
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

void enqueue(struct queue **frontref, struct queue **rearref, int value) {
    struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->data = value;
    newnode->next = NULL;

    if (*frontref == NULL && *rearref == NULL) {
        *frontref = newnode;
        *rearref = newnode;
        newnode->next = *frontref;
    } else {
        (*rearref)->next = newnode;
        (*rearref) = newnode;
        (*rearref)->next = *frontref;
    }
}

void dequeue(struct queue **frontref, struct queue **rearref) {
    if (*frontref == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct queue *temp = *frontref;
    if (*frontref == *rearref) {
        *frontref = NULL;
        *rearref = NULL;
    } else {
        *frontref = (*frontref)->next;
        (*rearref)->next = *frontref;
    }
    free(temp);
}

void display(struct queue *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct queue *temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}


