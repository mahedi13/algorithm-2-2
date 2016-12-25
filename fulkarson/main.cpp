#include<bits/stdc++.h>
#include<string.h>
#include<limits.h>
#include<queue>
#define n 6
using namespace std;
bool bfs(int s,int t,int gra[n][n],int par[n])
{
    bool visited [n];
    memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(s);
  //  int u=q.front();
    visited[s]=true;
    par[s]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0;v<n;v++)
        {
            if(visited[v]==false&&gra[u][v]>0)
            {
                q.push(v);
                par[v]=u;
                visited[v]=true;
            }
        }
    }
    return(visited[t]==true);

}

int fordfulkarson(int s,int t,int graph[n][n])
{
    int par[n];
    int u,v, gra[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)gra[i][j]=graph[i][j];
        int total=0;
    while(bfs(s,t,gra,par))
    {
           int path=10000;
           for(v=t;v!=s;v=par[v])
           {
               u=par[v];
               path=min(path,gra[u][v]);
           }
           for(v=t;v!=s;v=par[v])
           {
               u=par[v];
               gra[u][v] -=path;
               gra[v][u] +=path;
           }
           total +=path;
    }
    return total;
}

int main()
{
     int graph[n][n] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
        cout<<"flow = "<<fordfulkarson(0,1,graph);
}
