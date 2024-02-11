#include <stdio.h>
#define size 10
int stck[size],top=-1;
void push(int val)
    {
        if(top==-size-1)
            printf("Stack Overflow");
        else
            {
                stck[top++]=val;
            }
    }
void pop()
    {
        int val;
        if(top==-1)
            printf("Stack Underflow");
        else
            {
                if (top==0)
                    {
                        val=stck[top];
                        top=-1;
                        
                    }
                else
                    stck[top--]=val;
                printf("%d",val);   
            }
    }

void peek()
    {
        if(top==-1)
            printf("Stack underflow");
        else
            printf("%d",stck[top]);
    }
void display()
    {
        for(int i=0; i<=top; i++)
            {
            printf("%d",stck[i]);
            }
    }
void main()
    {
        printf("STACK\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
        int ch,val;
        printf("Enter your choice");
        scanf("%d",&ch);
        while(ch!=5)
        {
            switch(ch)
                {
                    case 1:
                        printf("enter the value");
                        scanf("%d",&val);
                        push(val);
                        break;
                    case 2:
                        pop();
                        break;
                    case 3:
                        peek();
                        break;
                    case 4:
                        display();
                        break;
                }
                printf("Enter your choice :");
                scanf("%d",&ch);

                }
        }



    