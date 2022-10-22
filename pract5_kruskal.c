#include <stdio.h>
int parent[20],r=0,heap[20];

int find(int i)
{
    if(parent[i]>0)
    i = parent[i];
    return i;
}

void unon(int i,int j) {
    parent[i]=j;
}

void insert(int i)  //Function to insert in heap //
{
    int j,temp;
    r++; //inserting a elemnt in heap//
    heap[r]=i;
    j=r/2; //finding parent of element//
    while(j!=0&&heap[j]>i)
    {
        temp = heap[j];
        heap[j] = i;
        heap[r] = temp;
        j = j/2;
    }
}

int delete()
{
    int i,j,temp,flag=0,re;
    re = heap[1];
    heap[1] = heap[r];
    r--;
    j = 1;
    while((2*j<=r)&&(flag==0))
    {
    if(heap[2*j]<heap[2*j+1])
    {
        i = 2*j;
    }
    else
    {
        i = 2*j+1;
    }
    if(heap[j]>heap[i])
    {
        temp = heap[j];
        heap[j] = heap[i];
        heap[i] = temp;
        flag=0;
        j=i;
    }
    else
    flag=1;
   
   
    }
    return re;
}





int main()
{
    int n,i,j,u,v,mincost=0,cost[20][20],p,q,tree[20][20],c,b,edge;
    printf("\nEnter the no. of vertices ");
    scanf("%d",&n);
   
    for(i=1;i<=n;i++)
    {
        parent[i]=-1;
    for(j=1;j<=n;j++)
    {
        cost[i][j]=0;
    }
    }
   
   printf("\nenter the no. of edges ");
   scanf("%d",&edge);
   
    for(i=1;i<=edge;i++)
    {
        printf("\nenter the %d edge and cost ",i);
        scanf("%d %d %d",&u,&v,&c);
        cost[u][v]=cost[v][u]=c;
        insert(c);
       
    }
    int node=0;
    while(node<(n-1))
    {
        b = delete();
       
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]==b)
                {
                u=i;
                v=j;
                break;
                }
               
            }
        }
       
        p=find(u);
        q=find(v);
       
       
        if(p!=q)
        {
          node=node+1;
          tree[node][1]=u;
          tree[node][2]=v;
          mincost=mincost+cost[u][v];
          unon(p,q);
        }
    }
   
    if(node!=n-1)
    {
        printf("\nNo spanning Tree");
    }
    else
    {
        printf("\nThe tree is \n");
        for(i=1;i<=node;i++)
        {
            printf("\n");
            for(j=1;j<=2;j++)
            {
                printf("%d ",tree[i][j]);
            }
        }
    printf("\nThe mincost is %d",mincost);
    }
   
   
   
   
}