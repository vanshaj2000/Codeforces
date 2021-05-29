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

void dfs(vector<set<int>> &adj,vector<int> &vis,vector<int> &ans,priority_queue<int,vector<int>,greater<int>> &chos)
{
    if(chos.size()==0)
        return;
    int ind=chos.top();
    chos.pop();
    ans.push_back(ind);
    for(auto it=adj[ind].begin();it!=adj[ind].end();it++)
    {
        int u=*it;
        if(!vis[u])
        {
            chos.push(u);
            vis[u]=1;
        }
    }
    dfs(adj,vis,ans,chos);
}
int main()
{
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].insert(y-1);
        adj[y-1].insert(x-1);
    }
    vector<int> ans;
    vector<int> vis(n,0);
    vis[0]=1;
    priority_queue<int,vector<int>,greater<int>> chos;
    chos.push(0);
    dfs(adj,vis,ans,chos);
    for(int i=0;i<n;i++)
        cout<<ans[i]+1<<" ";
    return 0;
}