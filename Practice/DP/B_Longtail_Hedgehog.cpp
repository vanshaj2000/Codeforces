#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int dfs(int ind,vector<vector<int>> &adj,vector<int> &vis,int curr,vector<int> &glob,vector<int> &dp)
{
    //cout<<ind+1<<endl;
    if(dp[ind]>=(curr))
        return INT_MIN;
    dp[ind]=curr;
    vis[ind]=1;
    glob[ind]=1;
    int ret=(curr)*(adj[ind].size());
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u]&&u>ind)
            ret=max(ret,dfs(u,adj,vis,curr+1,glob,dp));
    }
    vis[ind]=0;
    return ret;
}
int32_t main()
{
    fast_cin();
    int n,m,ans=0;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int> vis(n,0),glob(n,0),dp(n,1);
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]*adj[i].size());
        for(int j=0;j<adj[i].size();j++)
        {
            int u=adj[i][j];
            if(i<u)
                dp[u]=max(dp[u],1+dp[i]);
        }
    }
    cout<<ans;
}