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

pair<int,int> dfs(int ind,vector<vector<int>> &adj,int dep,vector<bool> &vis)
{
    vis[ind]=true;
    int flag=0;
    pair<int,int> ret={dep,ind};
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(vis[u]==false)
        {
            pair<int,int> tem=dfs(u,adj,dep+1,vis);
            ret=max(ret,tem);
        }
    }
    return ret;
}
int main()
{
    fast_cin();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int zzz=0;
    int t;
    cin>>t;
    int ans=0;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<vector<int>> adj(n+1);
        for(int j=0;j<n-1;j++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> vis(n+1,false);
        pair<int,int> r1=dfs(1,adj,0,vis);
        //cout<<r1.first<<endl;
        vector<bool> vis2(n+1,false);
        r1=dfs(r1.second,adj,0,vis2);
        ans+=r1.first;
    }
    cout<<ans;
    return 0;
}