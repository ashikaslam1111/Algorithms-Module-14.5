#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1000;
vector<pair<int,int>>adj[N];
const int inf=1e5;
int dist[N];
bool visited[N];
void dijkstra(int src);
int main()
{
    cin>>n>>m;
    for(int i=0; i<=n; i++)dist[i]=inf;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    /*
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" -> ";
        for(auto j:adj[i])
        {
            cout<<'('<<j.first<<','<<j.second<<')'<<" ";
        }
        cout<<endl;
    }
    */
    int src=4;
    dist[src]=0;
    dijkstra(src);
    for(int i=1; i<=n; i++)cout<<dist[i]<<" ";
    return 0;
}
void dijkstra(int src)
{
    for(int i=1; i<=n; i++)
    {
        int selected=-1;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]==true)continue;
            if(selected==-1 || dist[j]<dist[selected])selected=j;
        }
        visited[selected]=true;
        for(auto now:adj[selected])
        {
            if(dist[now.first]>dist[selected]+now.second)
                dist[now.first]= dist[selected]+now.second;
        }
    }
}
