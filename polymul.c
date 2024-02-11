#include <stdio.h>
#include <stdbool.h>
typedef struct poly
{
    int coeff;
    int exp;
}poly;

poly first[15],second [15],result[15],final[15];

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
int DupChk(int resultcount) 
{
    int i, j, k = 0;
    for (i = 0; i < resultcount; i++) 
    {
        int sum = result[i].coeff;
        for (j = i + 1; j < resultcount; j++) 
        {
            if (result[i].exp == result[j].exp) 
            {
                sum += result[j].coeff;
                result[j].exp = -1; // mark as processed
            }
        }
        if (result[i].exp != -1) 
        { // if not processed
            final[k].exp = result[i].exp;
            final[k].coeff = sum;
            k++;
        }
    }
    return k;
}

int MulExp(int firstcount,int secondcount)
    {
        int i=0,j=0,k=0;
        while(i<firstcount)
            {
                for(j=0;j<secondcount;j++)
                    {
                        result[k].coeff=first[i].coeff*second[j].coeff;
                        result[k].exp=second[j].exp+first[i].exp;
                        k++;
                    }
                i++;
            }
        return k;
    }

void main()
    {
        int firstcount,secondcount,resultcount,finalcount;
        firstcount = readExp(first);
        printf("First Polynomial:");
        display(first,firstcount);
        secondcount=readExp(second);
        printf("Second Polynomial:");
        display(second,secondcount);
        resultcount=MulExp(firstcount,secondcount);
        finalcount=DupChk(resultcount);
        printf("Resultant polynomial:");
        display(final,finalcount);
        

    }
