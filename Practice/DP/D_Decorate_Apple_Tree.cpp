#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int dfs(int ind,vector<vector<int>> &adj,vector<int> &vis,vector<int> &nums)
{
    vis[ind]=1;
    int ret=0,ch=0,t=0;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            ret+=dfs(u,adj,vis,nums),ch++;
    }
    if(ch==0)
        return 1;
    return nums[ind]=ret;
}
int32_t main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<int> nums(n,0),vis(n,0),ans(n+1),vis2(n,0);
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        adj[i+1].push_back(x-1);
        adj[x-1].push_back(i+1);
    }
    int temp=dfs(0,adj,vis,nums);
    //cout<<temp<<endl;
    for(int i=1;i<=temp;i++)
        ans[i]=1;
    ans[n]=temp;
    vis2[0]=1;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<adj[0].size();i++)
        pq.push({nums[adj[0][i]],adj[0][i]});
    for(int i=n-1;i>temp;i--)
    {
        pair<int,int> temp=pq.top();
        pq.pop();
        ans[i]=temp.first;
        //cout<<temp.second<<" "<<temp.first<<" ";
        vis2[temp.second]=1;
        for(int j=0;j<adj[temp.second].size();j++)
        {
            int u=adj[temp.second][j];
            //cout<<u<<" ";
            if(!vis2[u])
                pq.push({nums[u],u});
        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}