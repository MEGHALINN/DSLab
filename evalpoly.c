#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct poly
{
    int coeff;
    int exp;
}poly;

poly first[15],second [15],result[15];

void display(poly ply[],int count)
    {
        int i=0;
        for(i=0;i<count;i++)
            {
                printf("%dx^%d\t",ply[i].coeff,ply[i].exp);
                if(i<count-1)
                    printf("+");
            }
        
    }

int readExp(poly ply[])
    {
        int terms,i;
        printf("Enter the no of terms :");
        scanf("%d",&terms);
        printf("Enter the polynomial in descending order\n");
        for(i=0;i<terms;i++)
            {
                printf("Enter the coefficient and exponent");
                scanf("%d",&ply[i].coeff);
                scanf("%d",&ply[i].exp);
            }
        return terms;
    }

void evalpol(poly ply[],int count,int x)
    {
        int i,j,sum=0;
        for(i=0;i<count;i++)
            {
                sum=sum+ ply[i].coeff*(pow(x,ply[i].exp));
            }
        printf("%d",sum);
    }


void main()
    {
        int firstcount,x;
        firstcount = readExp(first);
        printf("Polynomial:");
        display(first,firstcount);
        printf("Enter the value of x");
        scanf("%d",&x);
        printf("Result :");
        evalpol(first,firstcount,x);

    }
