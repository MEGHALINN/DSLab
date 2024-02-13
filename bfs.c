#include <stdio.h>
#include <stdlib.h>

void bfs(int startv,int visited[20],int adjList[20][20],int numVer)
    {
        int queue[20];
        int front=-1,rear=-1;
        queue[++rear]=startv;
        visited[startv]=1;
        while(front!=rear)
            {
                int curV=queue[++front];
                printf("%d",curV);
                for(int i=0;i<numVer;i++)
                    {
                        if(adjList[startv][i]==1&&!visited[i])
                            {
                                queue[++rear]=i;
                                visited[i]=1;
                            }
                    }
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
        printf("BFS");
        for(i=0;i<numVer;i++){
            if(!visited[i])
                bfs(i,visited,adjList,numVer);
        }
    }