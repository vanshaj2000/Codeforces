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

int cons=4010;
int dfs(vector<vector<int>> &g,vector<vector<int>> &adj,int ind,int par)
{
    int res=cons;
    for(int i=0;i<g[ind].size();i++)
    {
        int u=g[ind][i];

        if(adj[par][u]==1)
        {
            int x=g[ind].size()+g[u].size();
            int y=g[ind].size();
            if(ind!=par)
                res=min(res,x);
            else
                res=min(res,y+dfs(g,adj,u,ind));
        }
    }
    return res;
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n,vector<int>(n,0));
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        adj[x][y]=1;
        adj[y][x]=1;
    }
    int ans=cons;
    for(int i=0;i<n;i++)
        ans=min(ans,dfs(g,adj,i,i));
    if(ans==cons)
        cout<<"-1";
    else
        cout<<ans-6;
    return 0;
}