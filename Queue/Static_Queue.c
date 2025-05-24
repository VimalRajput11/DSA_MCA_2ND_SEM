// Implement a static queue using an array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5



void Enqueue(int value);
void Dequeue();
void display();

int queue[SIZE];
int front = -1;
int rear = -1;

int main(){
    int choice,value;

    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
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

void Enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
    else
    {
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

void Dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("%d dequeued from queue\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}