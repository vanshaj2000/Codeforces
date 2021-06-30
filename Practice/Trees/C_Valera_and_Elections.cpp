#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
void dfs(vector<vector<pair<int,int>>> &adj,vector<int> &vis,int ind,vector<int> &p)
{
    vis[ind]=1;
    int ret=0;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i].first,r=adj[ind][i].second;
        if(!vis[u])
        {
            if(r==2)
                p[ind]++,p[u]++;
            dfs(adj,vis,u,p);
            p[ind]+=p[u];
        }
    }
}
int32_t main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x-1].push_back({y-1,z});
        adj[y-1].push_back({x-1,z});
    }
    vector<int> vis(n,0),p(n,0),ans;
    dfs(adj,vis,0,p);
    for(int i=0;i<n;i++)
    {
        if(p[i]==1)
            ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<" ";
}