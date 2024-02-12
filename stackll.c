#include <stdio.h>
#include <stdlib.h>
#define size 10
 typedef struct node{
    int data;
    struct node* next;
 }node;

 node* head=NULL;

node* createnode(int val)
    {
        node* new=(node*)malloc(sizeof(node));
        new->data=val;
        new->next=NULL;
        return new;
    }
void push(){
    int val;
    printf("Enter the value to be inserted");
    scanf("%d",&val);
    node* new=createnode(val);
    if(head==NULL)
        head=new;
    else{
        new->next=head;
        head=new;
    }
}
void pop()
    {
        if(head==NULL)
            printf("List empty");
        else{
            head=head->next;
        }
    }
void display()
    {
        node* temp=head;
        if(temp==NULL)
            printf("List is empty");
        else{
        while(temp!=NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
            }
        }
    }
void main()
    {
        push();
        push();
        push();
        push();
        display();
        pop();
        display();
        pop();
    }