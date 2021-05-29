#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int mod=1000000007;
void dfs(int ind,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &temp)
{
    vis[ind]=true;
    for(int i=0;i<adj[ind].size();i++)
    {
        if(!vis[adj[ind][i]])
            dfs(adj[ind][i],adj,vis,temp);
    }
    temp.push_back(ind);
}
int main()
{
    fast_cin();
    int n,k;
    cin>>n>>k;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        if(c==0)
        {
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
    }
    vector<bool> vis1(n,false);
    vector<int> temp1;
    for(int i=0;i<n;i++)
    {
        if(!vis1[i])
            dfs(i,adj,vis1,temp1);
    }
    vector<bool> vis(n,false);
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        if(!vis[temp1[n-i-1]])
        {
            vector<int> temp;
            dfs(temp1[n-i-1],adj,vis,temp);
            res.push_back(temp.size());
        }
    }
    //cout<<res[0]<<endl;
    int ans=0;
    int x=n;
    int te=n;
    for(int i=0;i<k-1;i++)
    {
        for(int i=0;i<n-1;i++)
            te=(te+x)%mod;
        x=te;
    }
    ans=x;
    for(int l=0;l<res.size();l++)
    {
        int y=res[l];
        int te=res[l];
        for(int i=0;i<k-1;i++)
        {
            for(int j=0;j<res[l]-1;j++)
                te=(te+y)%mod;
            y=te;
        }
        ans=(ans-y)%mod;
    }
    ans=(ans+mod)%mod;
    cout<<ans;
    return 0;
}