#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int deque[SIZE];
int front = -1;
int rear = -1;

void display();
void insert_from_front(int value);
void insertRear(int value);
void deleteFront();
void deleteRear();


int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insert_from_front(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void insert_from_front(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
    } else if (front == -1) { 
        front = rear = 0;
        deque[front] = value;
    } else if (front == 0) {
        front = SIZE - 1;
        deque[front] = value;
    } else {
        front--;
        deque[front] = value;
    }
    printf("%d inserted at front\n", value);
}

void insertRear(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[rear] = value;
    } else if (rear == SIZE - 1) {
        rear = 0;
        deque[rear] = value;
    } else {
        rear++;
        deque[rear] = value;
    }
    printf("%d inserted at rear\n", value);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else if (front == rear) {
        printf("%d deleted from front\n", deque[front]);
        front = rear = -1;
    } else if (front == SIZE - 1) {
        printf("%d deleted from front\n", deque[front]);
        front = 0;
    } else {
        printf("%d deleted from front\n", deque[front]);
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else if (front == rear) {
        printf("%d deleted from rear\n", deque[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("%d deleted from rear\n", deque[rear]);
        rear = SIZE - 1;
    } else {
        printf("%d deleted from rear\n", deque[rear]);
        rear--;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
