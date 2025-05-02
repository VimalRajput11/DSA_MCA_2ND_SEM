//InterSection of Two Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Linked_List(struct Node **headref, int newdata) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;

    if (*headref == NULL) {
        *headref = newnode;
    } else {
        struct Node *temp = *headref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct Node* Intersection_List(struct Node **headref1, struct Node **headref2)
{
    struct Node *temp1 = *headref1;
    struct Node *temp2 = *headref2;
    struct Node *result = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data == temp2->data)
        {
            Linked_List(&result, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->data < temp2->data)
        {
            temp1 = temp1->next;
        }
        else
        {
            temp2 = temp2->next;
        }
    }

    return result;
}



struct Node * getIntersectionNode(struct Node *head1, struct Node *head2) {
    if (head1 == NULL || head2 == NULL) {
        return NULL;
    }

    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    while (temp1 != temp2) {
        temp1 = (temp1 == NULL) ? head2 : temp1->next;
        temp2 = (temp2 == NULL) ? head1 : temp2->next;
    }

    return temp1; 

}

void display(struct Node *temp)
{
    printf("List elements are: ");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *intersection = NULL;

    Linked_List(&head1, 1);
    Linked_List(&head1, 2);
    Linked_List(&head1, 3);
    Linked_List(&head1, 4);
    Linked_List(&head1, 5);

    Linked_List(&head2, 1);
    Linked_List(&head2, 3);
    Linked_List(&head2, 5);

    display(head1);
    display(head2);

    intersection = Intersection_List(&head1, &head2);

    printf("Intersection List: ");
    display(intersection);

    struct Node *intersectionNode = getIntersectionNode(head1, head2);
    if (intersectionNode != NULL) {
        printf("Intersection Node: %d\n", intersectionNode->data);
    } else {
        printf("No intersection node found.\n");
    }

    return 0;
}