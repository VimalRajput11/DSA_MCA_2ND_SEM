#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;

int main(){

    struct node *temp;
    printf("%p %p\n",temp,head);
    temp=(struct node*)malloc(sizeof(struct node));
  temp->data=10;
    printf("%p %p\n",temp->data,temp->next);

    printf("%p %p\n",temp,head);
    

}