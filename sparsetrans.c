#include <stdio.h>
typedef struct 
    {
        int row;
        int col;
        int val;
    }sparse;
sparse a[100],b[100];

void trans(sparse sp[],sparse tp[],int r1)
    {
        int t,cur;
        tp[0].row=sp[0].row,tp[0].col=sp[0].col,tp[0].val=t=sp[0].val;
        if(t>0)
            {
            cur=1;
            for(int i=0;i<r1;i++)
                {
                for(int j=1;j<=t;j++)
                    {
                    if(sp[j].col==i)
                        {
                        tp[cur].row=sp[j].col;
                        tp[cur].col=sp[j].row;
                        tp[cur].val=sp[j].val;
                        cur++;
                        }
                        
                    }
                }
        
            }
        printf("Transpose is");
        for(int i=0;i<t+1;i++)
            {
                printf("%d %d %d",tp[i].row,tp[i].col,tp[i].val);
                printf("\n");
            }
    }

void main()
    {
        int r1;
        printf("Enter the no of rows in the triplet representation");
        scanf("%d",&r1);
        printf("Enter the matrix:");
        for(int i=0;i<r1;i++)
            {
                scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].val);
            }
        trans(a,b,r1);
    }