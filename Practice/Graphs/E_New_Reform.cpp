#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 1000000007;
double eps = 1e-12;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int flag;
void dfs(int par,int ind,vector<vector<int>> &adj,vector<int> &vis)
{
    vis[ind]=1;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            dfs(ind,u,adj,vis);
        else if(u!=par)
            flag=1;
    }
}
int main()
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
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            flag=0;
            dfs(i,i,adj,vis);
            ans+=(1-flag);
        }
    }
    cout<<ans;
    return 0;
}