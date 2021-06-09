#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class DSU
{
public:
    vector<int> par;
    vector<int> rank;
    DSU(int n)
    {
        par.resize(n,-1);
        rank.resize(n,1);
    }
    int find(int v)
    {
        if(par[v]==-1)
            return par[v]=v;
        return par[v]=find(par[v]);
    }
    void unite(int v1,int v2)
    {
        int p1=find(v1),p2=find(v2);
        if(rank[p1]>rank[p2])
        {
            rank[p1]+=rank[p2];
            par[p2]=p1;
        }
        else
        {
            rank[p2]+=rank[p1];
            par[p1]=p2;
        }
    }
};
int main()
{
    fast_cin();
    int n,m,maxi=0,inni=-1;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> vis(n,0),ind(n,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
        ind[x-1]++;
        ind[y-1]++;
        if(ind[x-1]>maxi)
            maxi=ind[x-1],inni=x-1;
        if(ind[y-1]>maxi)
            maxi=ind[y-1],inni=y-1;
    }
    queue<int> q;
    q.push(inni);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=1;
        for(int i=0;i<adj[x].size();i++)
        {
            int u=adj[x][i];
            if(!vis[u])
            {
                cout<<x+1<<" "<<u+1<<endl;
                vis[u]=1;
                q.push(u);
            }
        }
    }
    return 0;
}