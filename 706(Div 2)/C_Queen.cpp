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

void dfs(int ind,vector<vector<int>> &adj,vector<int> &res,vector<int> &ans)
{
    int flag=0;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        dfs(u,adj,res,ans);
        if(res[ind]==1&&res[u]==1)
            flag++;
    }
    if(adj[ind].size()!=0)
    {
        if(flag==adj[ind].size())
            ans.push_back(ind);
    }
    else
    {
        if(res[ind]==1)
            ans.push_back(ind);
    }
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    int root=-1;
    vector<int> res(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int p,c;
        cin>>p>>c;
        if(p==-1&&c==0)
            root=i;
        else
        {
            adj[p].push_back(i);
            res[i]=c;
        }
    }
    vector<int> ans;
    dfs(root,adj,res,ans);
    sort(ans.begin(),ans.end());
    if(ans.size()==0)
        cout<<"-1";
    else
    {
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    }
    return 0;
}