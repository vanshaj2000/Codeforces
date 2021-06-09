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

void dfs(int curr,int ind,int &mini,vector<vector<int>> &adj,vector<int> &vis)
{
    if(ind==adj.size()-1)
    {
        mini=min(curr,mini);
        return;
    }
    vis[ind]=1;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            dfs(curr+1,u,mini,adj,vis);
    }
}

int main()
{
    fast_cin();
    int n,m,mini1=INT_MAX,mini2=INT_MAX;
    cin>>n>>m;
    vector<vector<int>> vis(n,vector<int>(n,2));
    vector<vector<int>> adj(n),adjBus(n);
    for(int i=0;i<n;i++)
        vis[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        vis[x-1][y-1]=vis[y-1][x-1]=1;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]==2)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
                adj[i][j]=adj[j][i]=0;   
            }
        }
    }
    
    return 0;
}