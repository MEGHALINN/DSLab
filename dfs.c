#include <stdlib.h>
#include <stdio.h>
void dfs(int vertex,int visited[20],int adjList[20][20],int numVer)
    {
        printf("%d\t",vertex);
        visited[vertex]=1;
        for(int i=0;i<numVer;i++)
            {
                if(adjList[vertex][i]==1 && !visited[i])
                    dfs(i,visited,adjList,numVer);
            }
    }

void main()
    {
        int numVer,i,j;
        printf("Enter  the number of vertices");
        scanf("%d",&numVer);
        int adjList[20][20];
        printf("Enter the adjacency matrix");
        for(i=0;i<numVer;i++){
            for(j=0;j<numVer;j++){
                scanf("%d",&adjList[i][j]);
            }
        }
        int visited[20]={0};
        printf("DFS");
        for(i=0;i<numVer;i++){
            if(!visited[i])
                dfs(i,visited,adjList,numVer);
        }
    }