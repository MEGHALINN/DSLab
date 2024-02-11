#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;

node* createnode(int val){
    node* new=(node*)malloc(sizeof(node));
    if(new==NULL){
        printf("Allocation Failed");
    }
    else{
        new->data=val;
        new->next=NULL;
    }
}
void inserte()
    {
        int val;
        printf("Enter the value to be inserted");
        scanf("%d",&val);
        node* temp=head;
        if(temp==NULL)
            head=createnode(val);
        else{
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=createnode(val);
        }
    }

void insertf(){
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
void display()
    {
        node* temp=head;
        while(temp->next!=NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
            }
    }

void deletee()
    {
        node* head=temp;
        node* prev;
        if(head==NULL)
            printf("list empty");
        else{
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
        }
    }

void deletef()
    {
        if(head==NULL)
            printf("List empty");
        else{
            head=head->next;
        }
    }

void insertafter()
    {
        printf("Enter the value to bbe inserted");
        int val,ch;
        scanf("%d",&val);
        printf("Enter the node after which to be inserted");
        scanf("%d",&ch);
        node* temp=head;
        new=createnode(val);
        if(temp==NULL)
            head=new;
        else{
            while(temp->next!=NULL && temp->data!=ch)
                temp=temp->next;
            new->next=temp->next;
            temp->next=new;
        }
    }

void insertbefore()
    {
        printf("Enter the value to be inserted :");
        int val,ch;
        printf("Enter the node before which to be inserted :");
        scanf("%d",&ch);
        node* temp=head,curr;
        new=createnode(val);
        if(temp==NULL)
    }