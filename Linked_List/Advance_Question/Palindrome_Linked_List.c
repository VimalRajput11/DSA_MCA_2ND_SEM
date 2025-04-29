#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
void Linked_list(struct Node **headref, int newdata)
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

int isPalindrome(struct Node *head) {
    if (head == NULL || head->next == NULL)
        return 1; 

    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // if (fast != NULL) {
    //     slow = slow->next;
    // }
    struct Node *prev_rev = NULL, *curr = slow, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev_rev;
        prev_rev = curr;
        curr = next;
    }

    struct Node *first = head;
    struct Node *second = prev_rev;
    while (second != NULL) {
        if (first->data != second->data)
            return 0;
        first = first->next;
        second = second->next;
    }

    return 1; 
}


int main(){
    struct Node *head = NULL;
    Linked_list(&head, 1);
    Linked_list(&head, 2);
    Linked_list(&head, 3);
    Linked_list(&head, 3);
    Linked_list(&head, 2);
    Linked_list(&head, 1);
    // Linked_list(&head, 1);
    

    display(head);

   int result = isPalindrome(head);
    if (result) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }
    return 0;
}