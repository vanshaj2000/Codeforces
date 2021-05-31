#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
pair<int,int> dfs(int ind,vector<vector<int>> &adj,vector<int> &vis)
{
    vis[ind]=1;
    pair<int,int> ans={adj[ind].size(),1};
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
        {
            pair<int,int> temp=dfs(u,adj,vis);
            ans.first+=temp.first;
            ans.second+=temp.second;
        }
    }
    return ans;
}
int32_t main()
{
    fast_cin();
    int n,m,f=0,z=0;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            pair<int,int> res=dfs(i,adj,vis);
            if(res.first!=(res.second*(res.second-1)))
            {
                f++;
                break;
            }
        }
    }
    if(f)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}