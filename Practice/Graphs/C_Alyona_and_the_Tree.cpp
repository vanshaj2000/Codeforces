#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
#define int long long int
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void dfs(int ind,vector<vector<pair<int,int>>> &adj,vector<int> &vis,vector<int> &c,int curr)
{
    if(curr>c[ind])
        return;
    vis[ind]=1;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i].first,d=adj[ind][i].second;
        if(!vis[u])
        {
            int t=curr+d;
            if(t<0)
                t=0;
            dfs(u,adj,vis,c,t);
        }
    }
}
int32_t main()
{
    fast_cin();
    int n,ans=0;
    cin>>n;
    vector<int> c(n),vis(n,0);
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int i=0;i<n-1;i++)
    {
       int x,y;
       cin>>x>>y;
       adj[i+1].push_back({x-1,y});
       adj[x-1].push_back({i+1,y}); 
    }
    dfs(0,adj,vis,c,0);
    // for(int i=0;i<n;i++)
    //     cout<<vis[i]<<" ";
    // cout<<endl;
    for(int i=0;i<n;i++)
        ans+=(!vis[i])?1:0;
    cout<<ans;
    return 0;
}