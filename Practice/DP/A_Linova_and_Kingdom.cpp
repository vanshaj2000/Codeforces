#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int sum;
int dfs(int ind,vector<vector<int>> &adj,vector<pair<int,int>> &ans,vector<int> &vis,vector<int> &tour,int lev)
{
    vis[ind]=1;
    int num=1-tour[ind];
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            num+=dfs(u,adj,ans,vis,tour,lev+1);
    }
    ans.push_back({num-lev,ind});
    if(tour[ind])
        sum+=num;
    return num;
}
int32_t main()
{
    fast_cin();
    int n,k,ret=0;
    sum=0;
    cin>>n>>k;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<pair<int,int>> ans;
    vector<int> vis(n,0),tour(n,0),vis2(n,0);
    int fal=dfs(0,adj,ans,vis,tour,0);
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
    for(int i=0;i<n-k;i++)
        tour[ans[i].second]=1;
    int faltu=dfs(0,adj,ans,vis2,tour,0);
    cout<<sum;
    return 0;
}