#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int dfs(int ind,vector<vector<int>> &adj,vector<int> &cats,vector<bool> &vis,int m,int curr)
{
    vis[ind]=true;
    if(!cats[ind])
        curr=0;
    curr+=cats[ind];
    if(curr>m)
        return 0;
    int ret=0;
    int flag=0;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            ret+=dfs(u,adj,cats,vis,m,curr),flag++;
    }
    return (flag==0)?1:ret;
}
int main()
{
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<int> cats(n,0);
    for(int i=0;i<n;i++)
        cin>>cats[i];
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<bool> vis(n,false);
    cout<<dfs(0,adj,cats,vis,m,0);
    return 0;
}