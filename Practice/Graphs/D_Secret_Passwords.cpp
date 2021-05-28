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

void dfs(int ind,vector<vector<int>> &adj,vector<bool> &vis)
{
    vis[ind]=true;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            dfs(u,adj,vis);
    }
}
int main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<string> v;
    vector<int> vis(26,-1);
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        v.push_back(temp);
        for(int j=0;j<temp.size();j++)
        {
            if(vis[temp[j]-'a']==-1)
                vis[temp[j]-'a']=i;
            else
            {
                int u=vis[temp[j]-'a'];
                if(u!=i)
                {
                    adj[i].push_back(u);
                    adj[u].push_back(i);
                }
            }
        }
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<i<<" ";
        for(int j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }*/
    int ans=0;
    vector<bool> visi(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visi[i])
        {
            ans++;
            dfs(i,adj,visi);
        }
    }
    cout<<ans;
    return 0;
}