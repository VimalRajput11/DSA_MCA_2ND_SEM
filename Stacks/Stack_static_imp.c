#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int Top = -1;  
int stack[SIZE];
void push(int data)
{
    if (Top == SIZE - 1)
    {
        printf("Stack is overflow");
    }
    else
    {
        Top++;
        stack[Top] = data;
    }
}

void pop()
{
    if (Top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        printf(" Deleted Element:%d", stack[Top]);
        Top--;
    }
}

void display()
{
    if (Top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (int i = Top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{

    int choice, data;
    while (1)
    {
        printf("\nMenu\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter the choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert:");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);

        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}