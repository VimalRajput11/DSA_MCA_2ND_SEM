
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
struct Node *merge(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node *result = NULL;
    if (head1->data <= head2->data)
    {
        result = head1;
        result->next = merge(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merge(head1, head2->next);
    }
    return result;
}

struct Node *mergeKLists(struct Node **lists, int k)
{
    if (k == 0)
        return NULL;
    if (k == 1)
        return lists[0];
    while (k > 1)
    {
        int i = 0, j = 0;
        for (i = 0, j = 0; j < k - 1; i++, j += 2)
        {
            lists[i] = merge(lists[j], lists[j + 1]);
        }
        if (j == k - 1) 
        {
            lists[i] = lists[j];
            i++;
        }
        k = i;
    }

    return lists[0];
}

int main()
{
    int k = 3; 
    struct Node *lists[k];

    lists[0] = NULL;
    Linked_List(&lists[0], 5);
    Linked_List(&lists[0], 3);
    Linked_List(&lists[0], 1);

    lists[1] = NULL;
    Linked_List(&lists[1], 6);
    Linked_List(&lists[1], 4);
    Linked_List(&lists[1], 2);

    lists[2] = NULL;
    Linked_List(&lists[2], 9);
    Linked_List(&lists[2], 7);

    for (int i = 0; i < k; i++)
    {
        printf("List %d: ", i + 1);
        display(lists[i]);
    }
    struct Node *merged_list = mergeKLists(lists, k);
    printf("Merged Linked List: \n");
    display(merged_list);

    return 0;
}