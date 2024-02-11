#include <stdio.h>
#include <stdlib.h>
#define size 10
int stck[size],top=-1;
void sortedpush(int val)
    {
        int i;
        if(top==size-1)
            printf("Stack Overflow");
        else    
        {

            for( i=top;stck[i]>val;i--)
                {
                    stck[i+1]=stck[i];
                }
            stck[i+1]=val;
            top++;
        }
    }
void display()
    {
        if(top==-1)
            printf("Stack underflow");
        else
            {
                for(int i=0;i<=top;i++)
                    printf("%d\t",stck[i]);
            }
    }
void main()
    {
        printf("MENU \n1. SORTED PUSH\n2. DISPLAY\n3. EXIT\n");
        int ch,val;
        printf("Enter your choice");
        scanf("%d",&ch);
        while(ch!=3)
            {
                switch(ch)
                    {
                        case 1:
                            printf("Enter the value to be pushed");
                            scanf("%d",&val);
                            sortedpush(val);
                            break;
                        case 2:
                            display();
                            break;
                    }
                printf("Enter your choice ");
                scanf("%d",&ch);
            }

    }