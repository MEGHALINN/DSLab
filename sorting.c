#include <stdio.h>
int arr[50];
void insertionsort(int n)
    {
        int i=1;
        while(i<n)
            {
                int v=arr[i];
                int j=i;
                while((arr[j-1]>v)&&(j>0))
                    {
                        arr[j]=arr[j-1];
                        j--;
                    }
                arr[j]=v;
                i++;
            }
    }
void bubblesort(int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        
        for (j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            } 
        }
    }
}
void selectionsort(int n)
    {
        int i,j,min,temp;
        for(i=0;i<n-1;i++)
            {
                min=i;
                for(j=i+1;j<n;j++)
                    {
                        if(arr[j]<arr[min])
                            {
                                min=j;
                            }
                    }
                if(min!=i)
                    {
                        temp=arr[i];
                        arr[i]=arr[min];
                        arr[min]=temp;
                    }
                
            }
        
    }
int partition(int low,int high)
{
    int piv=arr[low],temp;
    int left=low+1;
    int right=high;
    while(1)
    {
        while(left <= right && arr[left] <= piv)
            left++;
        while(left <= right && arr[right] > piv)
            right--;
        if(left > right)
            break;
        else
        {
            temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
        }
    }
    arr[low]=arr[right];
    arr[right]=piv;
    return right;
}
void quicksort(int low,int high)
    {
         
        if(high>low)
            {
                int pivot=partition(low,high);
                quicksort(low,pivot-1);
                quicksort(pivot+1,high);
            }
    }

void display(int n)
    {
    printf("the sorted list is :\n");
            for(int i=0;i<n;i++)
                {
                printf("%d\t",arr[i]);
                }   
    }
void main()
    {
        int i,j,n,ch,low,high;
        printf("Enter the size of the array :");
        scanf("%d",&n);
        for(i=0;i<n;i++)
            {
                printf("Enter the element :");
                scanf("%d",&arr[i]);
            }
        printf("SORTING\n");
        printf("1.BUBBLE SORT\n");
        printf("2.INSERTION SORT\n");
        printf("3.SELECTION SORT\n");
        printf("4.QUICK SORT\n");
        printf("5.EXIT\n");
        printf("Enter your choice(1-7)");
        scanf("%d",&ch);
        while(ch!=5)
            {
            switch(ch)
                {
                    case 1:
                        bubblesort(n);
                        display(n);
                        break;
                    case 2:
                        insertionsort(n);
                        display(n);
                        break;

                    case 3:
                        selectionsort(n);
                        display(n);
                        break;
                    case 4:
                        low=0,high=n-1;
                        quicksort(low,high);
                        display(n);
                        break;
                }
            printf("Enter your choice(1-7)");
            scanf("%d",&ch);
            }
    }