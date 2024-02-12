#include <stdio.h>
#include <stdlib.h>
typedef struct node
	{
	int data ;
	struct node* next;
	}node;
node* front=NULL;
node* rear=NULL;
	
void enqueue()
	{
	node* newnode=(node*)malloc(sizeof(node));
	printf("Enter the value of new node");
	scanf("%d",&newnode->data);
	if(rear==NULL)
		{
		front=newnode;
		rear=newnode;
		}
	else
		{
		rear->next=newnode;
		rear=newnode;
		}
	}
void pop()
	{
	int val;
	if(front==NULL)
		{
		printf("Queue Empty");
		return;
		}
	else if(front==rear)
		{
		printf("Popped item :%d",front->data);
		front=rear=NULL;
		}
	else
		{
		printf("Popped item :%d",front->data);
		front=front->next;
	        }
	}
void display()
	{
	if(front==NULL)
		{
		printf("Queue empty");
		return;
		}
	else
		{
		node* temp=front;
		while(temp!=NULL)
			{
			printf("%d\t",temp->data);
			temp=temp->next;
			}
		}
	}
void main()
	{
	printf("QUEUE USING LINKED LIST");
	printf("\n 1.ENQUEUE \n 2.DEQUEUE\n 3.DISPLAY \n4.EXIT\n");
	int ch;
	printf("Enter your choice");
	scanf("%d",&ch);
	while(ch!=4)
		{
		if(ch==1)
			enqueue();
		if(ch==2)
			pop();
		if(ch==3)
			display();
		printf("Enter your choice");
		scanf("%d",&ch);
		}
	}
		
	
