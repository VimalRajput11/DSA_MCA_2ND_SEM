//Middle Node in Linked List in c

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head=NULL;

void Linked_List(struct Node **headref, int newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = (*headref);
    (*headref) = newnode;
}
void display(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int First_Middle_Node(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return -1; 
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}
int Second_Middle_Node(struct Node *head){

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return -1; 
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL )
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow->data;
}



int main(){
    Linked_List(&head, 6);
    Linked_List(&head, 5);
    Linked_List(&head, 4);
    Linked_List(&head, 3);
    Linked_List(&head, 2);
    Linked_List(&head, 1);
    display(head);
    int middle=First_Middle_Node(head);
    printf("First Middle Node is: %d\n", middle);
    int middle2=Second_Middle_Node(head);
    printf(" Second Middle Node is: %d\n", middle2);
}