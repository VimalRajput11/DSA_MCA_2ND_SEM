#include <stdio.h>
#include <stdlib.h>


struct queue{
    int data;
    struct queue *next;
};

void Enqueue(struct queue **frontref, struct queue **rearref, int value);
void Dequeue(struct queue **frontref, struct queue **rearref);
 void display(struct queue *front);

int main(){
    int choice,value;
    struct queue * front =NULL;
    struct queue *rear=NULL;

    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                Enqueue(&front, &rear, value);
                break;
            case 2:
                Dequeue(&front, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
               exit(1);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void Enqueue(struct queue **frontref, struct queue **rearref, int value)
{
    struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
    newNode->data = value;
    newNode->next = NULL;

    if (*frontref == NULL)
    {
        *frontref = newNode;
        *rearref = newNode;
    }
    else
    {
        (*rearref)->next = newNode;
        *rearref = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

void Dequeue(struct queue **frontref, struct queue **rearref)
{
    if (*frontref == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct queue *temp = *frontref;
    printf("%d dequeued from queue\n", temp->data);
    *frontref = (*frontref)->next;
    if (*frontref == NULL)
        *rearref = NULL;
    free(temp);
}

void display(struct queue *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct queue *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}