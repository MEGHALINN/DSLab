#include <stdio.h>
#include <stdlib.h>
#define size 10
int queue[size],front=-1,rear=-1;
void enqueue(int val)
    {
        if(front==-1)
            {
                front=rear=0;
                queue[rear]=val;
            }
        else
            {
            if(front==(rear+1)%size)
                {
                    printf("The queue is full");
                }
            else
                {
                    rear=(rear+1)%size;
                    queue[rear]=val;
                }
            }
    }

void dequeue()
    {
        if(front==-1)
            {
                printf("The queue is empty");
            }
        else
            {
                if(front==rear)
                    front=rear=-1;
                else
                    {
                        front=(front+1)%size;
                    }
            }
    }

void display()
    {
        for(int i=front;i!=rear;i=(i+1)%size)
            {
                printf("%d\t",queue[i]);
            }
    }
void main()
    {
        printf("QUEUE\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT");
        int val,ch;
        printf("Enter the choice");
        scanf("%d",&ch);
        while(ch!=4)
            {
                switch(ch)
                    {
                        case 1:
                            printf("Enter the value to be inserted");
                            scanf("%d",&val);
                            enqueue(val);
                            break;
                        case 2:
                            dequeue();
                            break;
                        case 3:
                            display();
                            break;
                    }
                printf("Enter the choice");
                scanf("%d",&ch);
            }
    }