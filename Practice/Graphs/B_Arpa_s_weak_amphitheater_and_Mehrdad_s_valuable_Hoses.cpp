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
pair<int,int> dfs(int ind,vector<vector<int>> &adj,vector<int> &vis,vector<int> &temp,vector<int> &we,vector<int> &b)
{
    vis[ind]=1;
    int weight=we[ind],butt=b[ind];
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
        {
            pair<int,int> t2=dfs(u,adj,vis,temp,we,b);
            weight+=t2.first;
            butt+=t2.second;
        }
    }
    temp.push_back(ind);
    return {weight,butt};
}
int main()
{
    fast_cin();
    int n,m,w;
    cin>>n>>m>>w;
    vector<int> we(n),b(n),vis(n,0);
    for(int i=0;i<n;i++)
        cin>>we[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    vector<vector<int>> adj(n),comp;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    int curr=n;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vector<int> temp;
            pair<int,int> tt=dfs(i,adj,vis,temp,we,b);
            we.push_back(tt.first),b.push_back(tt.second);
            temp.push_back(curr);
            curr++;
            comp.push_back(temp);

        }
    }
    //cout<<"Hello"<<endl;
    int n2=comp.size();
    vector<vector<int>> dp(n2+1,vector<int>(w+1,0));
    for(int i=1;i<=n2;i++)
    {
        for(int k=1;k<=w;k++)
        {
            for(int j=0;j<comp[i-1].size();j++)
            {
                int u=comp[i-1][j];
                if(we[u]<=k)
                    dp[i][k]=max(dp[i][k],max(b[u]+dp[i-1][k-we[u]],dp[i-1][k]));
                else
                    dp[i][k]=max(dp[i][k],dp[i-1][k]);
            }       
        }
    }
    cout<<dp[n2][w];
    return 0;
}