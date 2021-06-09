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
unordered_map<int,int> ump;
vector<int> col,vis;
vector<vector<int>> adj;
int maxi;
int dfs(int ind)
{
    ump[col[ind]-1]++;
    vis[ind]=1;
    maxi=max(maxi,ump[col[ind]-1]);
    int ret=1;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            ret+=dfs(u);
    }
    return ret;
}
int main()
{
    fast_cin();
    int n,m,k,ans=0;
    scanf("%d%d%d",&n,&m,&k);
    col.resize(n,0);
    vis.resize(n,0);
    adj.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&col[i]);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y)
            continue;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&adj[i].size()>0)
        {
            ump.clear();
            maxi=1;
            int temp=dfs(i);
            ans+=temp-maxi;
        }
    }
    cout<<ans;
    adj.clear();
    col.clear();
    vis.clear();
    return 0;
}