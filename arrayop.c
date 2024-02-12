//perform array operations
#include <stdio.h>
void print(int arr[50],int n)
    {
        for(int i=0;i<n;i++)
            {
                printf("%d\t",arr[i]);
            }
    }
void insert(int arr[50],int n)
    {
        int pos,val,i=n;
        printf("Enter the value to be inserted :");
        scanf("%d",&val);
        printf("Enter the position to be inserted :");
        scanf("%d",&pos);
        while(i>(pos-1))
            {
                arr[i]=arr[i-1];
                i--;
            }
        arr[pos-1]=val;
        print(arr,n);

    }

void main()
    {
        int arr[50],n,i;
        printf("Enter the size of the array :");
        scanf("%d",&n);
        for(i=0;i<n;i++)
            {
                printf("Enter the element :");
                scanf("%d",&arr[i]);
            }
        printf("QUEUE\n 1, INSERT\n 2. SEARCH \n 3. SORT\n 4. EXIT\n");
        printf("Enter your choice :");
        int ch;
        scanf("%d",&ch);
        while(ch!=4)
            {
                if(ch==1)
                    insert(arr,n);
                /*else if (ch==2)
                    search(arr);
                else if (ch==3)
                    sort(arr);*/
                printf("Enter your choice :");
                scanf("%d",&ch);
                
            }
    }