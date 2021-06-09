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
int rem;
void dfs(int ind,int cpar,int cme,vector<vector<int>> &adj,vector<int> &vis,vector<int> &ans)
{
    vis[ind]=1;
    //cout<<ind<<" "<<cme<<endl;
    ans[ind]=cme;
    int cs=cme+1;
    //cout<<ind<<" "<<cs<<endl;
    for(int i=0;i<adj[ind].size();i++)
    {
        
        int u=adj[ind][i];
        if(!vis[u])
        {
            if(cs>rem)
                cs-=rem;
            if(cs==cpar)
                cs++;
            if(cs>rem)
                cs-=rem;
            //cout<<u<<" "<<cs<<endl;
            dfs(u,cme,cs,adj,vis,ans);
            cs++;
        }
    }
}
int main()
{
    fast_cin();
    rem=0;
    int n,ans=0;
    cin>>n;
    vector<int> ind(n+1,1),a(n+1),vis(n+1,0);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        ind[x]++,ind[y]++;
        ans=max(ans,max(ind[x],ind[y]));
    }
    rem=ans;
    dfs(1,1,1,adj,vis,a);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}