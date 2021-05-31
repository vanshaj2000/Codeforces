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

void dfs(int ind,vector<vector<int>> &adj,vector<int> &vis,vector<int> &temp)
{
    vis[ind]=true;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            dfs(u,adj,vis,temp);
    }
    temp.push_back(ind);
}

int main()
{
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> deg(n,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
        deg[x-1]++,deg[y-1]++;
    }
    vector<int> vis1(n,0),temp,vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis1[i])
            dfs(i,adj,vis1,temp);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        vector<int> temp1;
        if(!vis[temp[n-i-1]])
        {
            dfs(temp[n-i-1],adj,vis,temp1);
            int flag=1;
            for(int j=0;j<temp1.size();j++)
            {
                if(deg[temp1[j]]!=2)
                {
                    flag--;
                    break;
                }
            }
            ans+=flag;
        }
    }
    cout<<ans;
    return 0;
}