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
void addsparse(int a[20][20],int b[20][20],int row1,int col1)
    {
        int i=0,j=0,k=1,l=1,m=1;
        trip[0][0]=a[0][0];
        trip[0][1]=a[0][1];
        for(i=0;i<row1;i++)
            {
                for(j=0;j<col1;j++)
                    {
                        if ((a[k][0]==i) &&( a[k][1]==j) && (b[l][0]==i) && (b[l][1]==j))
                            {
                                trip[m][0]=a[k][0];
                                trip[m][1]=a[k][1];
                                trip[m][2]=a[k][2] +b[l][2];
                                m++,k++,l++;
                            }
                        else if ((a[k][0])==i && (a[k][1]==j))
                            {
                                trip[m][0]=a[k][0];
                                trip[m][1]=a[k][1];
                                trip[m][2]=a[k][2];
                                m++,k++;
                            }
                        else if ((b[l][0]==i) && (b[l][1]==j))
                            {
                                trip[m][0]=b[l][0];
                                trip[m][1]=b[l][1];
                                trip[m][2]=b[l][2];
                                k++,l++;
                            }
                    }
            }
        trip[0][2]=m-1;
       for (i = 0; i <m; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", trip[i][j]);
        }
        printf("\n");  // Corrected '\n' position
    }

    }
void main()
    {
    int row1,col1,t1,t2,row2,col2,i,j,a[20][20],b[20][20];
    printf("Enter the no of rows in matrix1:");
    scanf("%d",&row1);
    printf("Enter the no of columns in matrix 1 :");
    scanf("%d",&col1);
    printf("Enter the no of non-zero values in matrix1 :");
    scanf("%d",&t1);
    a[0][0]=row1;
    a[0][1]=col1;
    a[0][2]=t1;
    for(i=1;i<t1+1;i++)
        {
            for(j=0;j<3;j++)
                {
                    printf("Enter the element :");
                    scanf("%d",&a[i][j]);
                }
        }
    display(a,t1+1,3);
    printf("Enter the no of rows in matrix2:");
    scanf("%d",&row2);
    printf("Enter the no of columns in matrix 2 :");
    scanf("%d",&col2);
    printf("Enter the no of non-zero values in matrix 2 :");
    scanf("%d",&t2);
    for(i=1;i<t2+1;i++)
        {
            for(j=0;j<3;j++)
                {
                    printf("Enter the element :");
                    scanf("%d",&b[i][j]);
                }
        }
    b[0][0]=row2;
    b[0][1]=col2;
    b[0][2]=t2;
    display(b,t2+1,3);
    addsparse(a,b,row1,col1);
    }