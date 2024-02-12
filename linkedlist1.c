#include <stdio.h>
#include <stdlib.h>
#define size 10
int stck[size],top=-1;

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

void minimumelem()
    {
        node* temp=head;
        int min=head->data;
        while(temp!=NULL)
            {
                if(temp->data<min)
                    min=temp->data;
                temp=temp->next;
            }
        printf("The minimum element is %d",min);
    }

void deletekey()
    {
        node* temp=head,*curr;
        int key;
        printf("Enter the node to be deleted");
        scanf("%d",&key);
        while(temp!=NULL&&temp->data!=key)
            {
                curr=temp;
                temp=temp->next;
            }
        if(temp==NULL)
            printf("Node not found");
        else
            {
                curr->next=temp->next;
            }
    }

void deletepos()
    {
        int pos,count=1;
        printf("Enter the position to be deleted");
        scanf("%d",&pos);
        node* temp=head,*curr;
        if(temp==NULL)
            {
                printf("The list is empty");
            }
        else{
            if (pos==1){
                head=head->next;
                free(temp);
            }
            else{
                while(count!=pos)
                    {
                        count++;
                        curr=temp;
                        temp=temp->next;
                    }
                curr->next=temp->next;
                free(temp);
            }
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
void push(int val)
    {
        if(top==size-1)
           // printf("Stack Overflow");
           exit(1);
        else
            {
                stck[++top]=val;
            }
    }
int pop()
    {
        int val;
        if(top==-1)
            //printf("Stack Underflow");
            return -1;
        else
            {
             val=stck[top--];       
            }
        return val;
    }

void reversepush()
{
    node* temp=head;
    if(head==NULL)
        printf("List Empty");
    else{
        while(temp!=NULL){
            push(temp->data);
            temp=temp->next;
        }
    }
}

void reversepop()
    {
        node* temp=head;
        int val;
        while(temp!=NULL){
            val=pop();
            if(val!=-1){
                temp->data=val;
                temp=temp->next;
            }
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

void deletee()
    {
        node* temp=head;
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
        node* new=createnode(val);
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
        scanf("%d",&val);
        printf("Enter the node before which to be inserted :");
        scanf("%d",&ch);
        node* temp=head,*curr;
        node* new=createnode(val);
        if(temp==NULL)
            head=new;
        else{
            while(temp->next!=NULL && temp->data!=ch){
                curr=temp;
                temp=temp->next;
            }
            curr->next=new;
            new->next=temp;
        }
    }
void main()
    {
        printf("LINKED LIST \n1. INSERT AT END\n2. INSERT AT FRONT\n3. INSERT AFTER A NODE\n4. INSERT BEFORE A NODE\n5. DELETE FROM FRONT\n6. DELETE FROM END\n7. DISPLAY\n8. MINIMUM ELEMENT\n9. DELETE KEY\n10. DELETE AT POSITION\n11. REVERSE LIST\n12. EXIT\n");
        printf("Enter your choice");
        int ch;
        scanf("%d",&ch);
        while(ch!=12)
            {
                switch(ch)
                    {
                        case 1:
                            inserte();
                            break;
                        case 2:
                            insertf();
                            break;
                        case 3:
                            insertafter();
                            break;
                        case 4:
                            insertbefore();
                            break;
                        case 5:
                            deletef();
                            break;
                        case 6:
                            deletee();
                            break;
                        case 7:
                            display();
                            break;
                        case 8:
                            minimumelem();
                            break;
                        case 9:
                            deletekey();
                            break;
                        case 10:
                            deletepos();
                            break;
                        case 11:
                            reversepush();
                            reversepop();
                            display();
                            break;
                        default:
                            printf("Invalid choice");
                    }
                printf("Enter your choice");
                scanf("%d",&ch);
            }
    }