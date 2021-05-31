#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
pair<int,int> dfs(int ind,vector<vector<int>> &adj,vector<int> &vis)
{
    vis[ind]=1;
    pair<int,int> ans={1,adj[ind].size()};
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> home(k);
    vector<vector<int>> adj(n);
    for(int i=0;i<k;i++)
        cin>>home[i],home[i]--;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int> vis(n,0);
    vector<pair<int,int>> pr;
    for(int i=0;i<k;i++)
        pr.push_back(dfs(home[i],adj,vis));
    int ans=0;
    for(int i=0;i<k;i++)
        ans+=(((pr[i].first*(pr[i].first-1))-pr[i].second)/2);
    sort(pr.begin(),pr.end());
    int num=pr[k-1].first;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            pair<int,int> temp=dfs(i,adj,vis);
            ans+=(((temp.first*(temp.first-1))-temp.second)/2);
            ans+=temp.first*num;
            num+=temp.first;
        }
    }
    cout<<ans;
    return 0;
}