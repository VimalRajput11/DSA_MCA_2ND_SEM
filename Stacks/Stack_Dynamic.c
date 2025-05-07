#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*Top=NULL;

void push(struct node **Topref,int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack overflow\n");
        return;
    }
    newnode->data = data;
    newnode->next = *Topref;
    *Topref = newnode;
}

void pop(struct node **Topref)
{
    if (*Topref == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    struct node *temp = *Topref;
    printf("Deleted Element: %d\n", (*Topref)->data);
    *Topref = (*Topref)->next;
    free(temp);
}

void display()
{
    if (Top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = Top;
    printf("Stack elements are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
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
            push(&Top,data);
            break;
        case 2:
            pop(&Top);
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