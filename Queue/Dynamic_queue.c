#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

void Enqueue(struct node **frontref, struct node **rearref, int value);
void Dequeue(struct node **frontref, struct node **rearref);
void display(struct node *front);

int main(){
    int choice,value;
    struct node * front =NULL;
    struct node *rear=NULL;

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

void Enqueue(struct node **frontref, struct node **rearref, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
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

void Dequeue(struct node **frontref, struct node **rearref)
{
    if (*frontref == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = *frontref;
    printf("%d dequeued from queue\n", temp->data);
    *frontref = (*frontref)->next;
    if (*frontref == NULL)
        *rearref = NULL;
    free(temp);
}

void display(struct node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}