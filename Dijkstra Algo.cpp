#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll i,j,k,t,n,e,u,v,w;
ll dis[10000];
vector<pair<ll,ll> >adj[1000];
bool vis[10000];
const ll inf = 1000009;
void dijkstra(int src)
{
    for(i=0; i<=n; i++)
        dis[i]=inf, vis[i]=0;

    dis[src]=0;
    for(ll i=1; i<=n; i++)
    {
        ll u=-1;
        for(ll j=1; j<=n; j++)
        {
            if(vis[j]==0 && (u==-1 || dis[j]<dis[u]))
                u=j;
        }
       // cout<<i<<' '<<u<<endl;
        vis[u]=1;

        for(vector<pair<ll,ll> >::iterator nd = adj[u].begin(); nd!=adj[u].end(); nd++)// for(pair <int, int> nd: adj[u]){  int v = nd.first, w = nd.second ;

        {
            ll v=nd->first, w=nd->second;
            if(dis[u]+w<dis[v])
                dis[v]=dis[u]+w;
        }
    }
}

int main()
{
    cin>>n>>e;
    for(i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src=1;
    dijkstra(src);
    for(i=1;i<=n;i++)
        cout<<i<<" : "<<dis[i]<<endl;
    return 0;
}

/*
7 8
1 2 3
1 3 4
1 5 5
2 3 6
3 4 2
3 7 1
6 7 3
5 6 2
*/
