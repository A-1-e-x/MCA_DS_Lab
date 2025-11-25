#include<stdio.h>
#include<stdlib.h>
  
int visited[100];
int stack[100],top=-1;


void push(int value)
{
	stack[++top]=value;
}

int pop()
{
	if(top ==-1)
	{
      		return -1;
      	}
 	else
 	{
    		return stack[top--];
    	}
}	

void dfs(int adj[10][10],int start,int n)
{
	int i;
	push(start);
 	visited[start]=1;
	printf("DFS Traversal:");
	while(top!=-1)
	{
 		int current=pop();
 		printf(" %d ",current);
 		for(i=n-1;i>=0;i--)
		{
     			if(adj[current][i]==1&&!visited[i])
     			{
         			push(i);
         			visited[i]=1;
      			}
		}
	}
}


int main()
{
 	int n,adj[10][10],i,j,start;
 	printf("Enter number of vertices:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
  		for(j=0;j<n;j++)
  		{
     			scanf("%d",&adj[i][j]);
   		}
   	}
	printf("Enter starting vertex (0 t0 %d):",n-1);
	scanf("%d",&start);
	dfs(adj,start,n);
	return 0;
}

