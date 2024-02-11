#include <stdio.h>
int stck[100],top=-1;
void push(int val)
    {
        stck[++top]=val;
    }
int pop()
    {
        if(top==-1)
            {
                printf("Stack underflow");
                return;
            }
        return stck[top--];
    }
int evalpostfix(char postfix[20])
    {
        int i=0,x,y;
        while(postfix[i]!='\0')
            {
                if(isdigit(postfix[i]))
                    {
                        push(postfix[i]-'0');
                    }
                else    
                {
                    x=pop();
                    y=pop();
                    switch(postfix[i])
                        {
                            case '+':
                                push(y+x);
                                break;
                            case '-':
                                push(y-x);
                                break;
                            case '/':
                                push(y/x);
                                break;
                            case '*':
                                push(y*x);
                                break;
                        }
                }
                i++;
            }
        return pop();
    }
void main()
    {
        char postfix[20];
        int res;
        printf("Enter the postfix expression");
        scanf("%s",postfix);
        res=evalpostfix(postfix);
        printf("Thevalue after evaluation is : %d",res);
    }