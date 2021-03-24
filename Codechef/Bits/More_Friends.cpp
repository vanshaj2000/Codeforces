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

void dfs(vector<vector<int>> &adj,int ind,vector<bool> &vis)
{
    vis[ind]=true;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(vis[u]==false)
            dfs(adj,u,vis);
    }
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int n,f;
    cin>>n>>f;
    vector<vector<int>> adj(n);
    for(int i=0;i<f;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n,false);
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            dfs(adj,i,vis);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}