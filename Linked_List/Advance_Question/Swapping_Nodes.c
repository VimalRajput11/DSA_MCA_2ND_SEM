//Swapping Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Linked_List(struct Node **headref, int newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;

    if (*headref == NULL)
    {
        *headref = newnode;
    }
    else
    {
        struct Node *temp = *headref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
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

//swap Kth node from 
void Kth_Swape_Nodes (struct Node **headref, int k)
{
    struct Node *temp = *headref;
    struct Node *prev = NULL;
    struct Node *current = *headref;
    int count = 1;

    while (count < k && current != NULL)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Swapping not possible\n");
        return;
    }

    struct Node *next_node = current->next;
    current->next = next_node->next;
    next_node->next = current;

    if (prev != NULL)
    {
        prev->next = next_node;
    }
    else
    {
        *headref = next_node;
    }
}

int main(){
    struct Node *head = NULL;
    Linked_List(&head, 1);
    Linked_List(&head, 2);
    Linked_List(&head, 3);
    Linked_List(&head, 4);
    Linked_List(&head, 5);
    Linked_List(&head, 6);
    Linked_List(&head, 7);
    display(head);
    int k = 3;
    Kth_Swape_Nodes(&head, k);
    printf("After Swapping %dth node with %dth node\n", k, k+1);
    display(head);
    return 0;


}
