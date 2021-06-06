#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define double long double
double func(int ind,vector<vector<int>> &adj,vector<int> &vis,int curr)
{
    vis[ind]=1;
    double ans=0,c=0;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
        {
            c++;
            ans+=(func(u,adj,vis,curr+1));
        }
    }
    if(c==0)
        return curr;
    else
        return ((1/c)*(ans));
}
int32_t main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int> vis(n,0);
    cout<<fixed<<setprecision(15)<<func(0,adj,vis,0);
    return 0;
}