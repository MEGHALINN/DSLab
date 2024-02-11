#include <stdio.h>
#include <stdlib.h>
int trip[][20];
void display(int res[][20],int row,int col)
    {
        int i,j;
        for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                    {
                        printf("%d\t",res[i][j]);
                    }
                printf("\n");
            }
    }
void contotrip(int row,int col,int a[20][20])
    {
        int i,j,k=1;
        trip[0][0]=row,trip[0][1]=col;
        for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                    {
                        if(a[i][j]!=0)
                            {
                                trip[k][0]=i;
                                trip[k][1]=j;
                                trip[k][2]=a[i][j];
                                k++;
                            }
                    }
            }
        a[0][2]=k-1;
        display(trip,k,3);
    }

void main()
    {
    int row,col,i,j,a[20][20];
    printf("Enter the no of rows :");
    scanf("%d",&row);
    printf("Enter the no of columns:");
    scanf("%d",&col);
    printf("Enter the matrix elements:");
    for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                {
                    printf("Enter the element:");
                    scanf("%d",&a[i][j]);
                }
        }
    printf("Entered matrix:");
    display(a,row,col);
    contotrip(row,col,a);
    }