#include <stdio.h>
#include <stdlib.h>
#define size 10
int queue[size],front=-1,rear=-1;
void enqueue(int val)
    {
        if(rear==size-1)
            {
                printf("Queue is full");
                exit(1);
            
            }
        if(front==-1)
            {
            front=rear=0;
            queue[front]=val;
            }
        else   
            queue[++rear]=val;
    }
int dequeue()
    {
        int val;
        if(front==-1)
            {
            printf("Queue is empty");
            exit(1);
            }
        val=queue[front];
        if(front==size-1)
            {
            front=rear=-1;
            }
        else
            {
            front++;
            }
        return val;
    }

void display()
    {
        for(int i=front;i<=rear;i++)
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
                            printf("The dequeued element is %d",dequeue());
                            break;
                        case 3:
                            display();
                            break;
                    }
                printf("Enter the choice");
                scanf("%d",&ch);
            }
    }