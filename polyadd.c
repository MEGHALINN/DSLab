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

int addExp(int firstcount,int secondcount)
    {
        int i=0,j=0,k=0;
        while(i<firstcount&&j<secondcount)
            {
                if(first[i].exp==second[j].exp)
                    {
                        result[k].coeff=first[i].coeff+second[j].coeff;
                        result[k].exp=first[i].exp;
                        i++,j++,k++;
                    }
                if(first[i].exp>second[j].exp)
                    {
                        result[k].coeff=first[i].coeff;
                        result[k].exp=first[i].exp;
                        i++,k++;
                    }
                if(first[i].exp<second[j].exp)
                    {
                        result[k].coeff=second[j].coeff;
                        result[k].exp=second[j].exp;
                        k++,j++;
                    }
            }
        while(i<firstcount)
            {
                result[k].coeff=first[i].coeff;
                result[k].exp=first[i].exp;
                i++,k++;  
            }
        while(j<secondcount)
            {
                result[k].coeff=second[j].coeff;
                result[k].exp=second[j].exp;
                k++,j++;   
            }
        return k;
    }

void main()
    {
        int firstcount,secondcount,resultcount;
        firstcount = readExp(first);
        printf("First Polynomial:");
        display(first,firstcount);
        secondcount=readExp(second);
        printf("Second Polynomial:");
        display(second,secondcount);
        resultcount=addExp(firstcount,secondcount);
        printf("Resultant polynomial:");
        display(result,resultcount); 

    }
