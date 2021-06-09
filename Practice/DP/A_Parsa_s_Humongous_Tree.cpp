#include<bits/stdc++.h>
#define int long long int
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
/*Dp formulation
dp[par][l]+=max(dp[child][l]+|lpar-lchild|,dp[child][r]+|lpar-rchild|)
dp[par][r]+=max(dp[child][l]+|rpar-lchild|,dp[child][r]+|rpar-rchild|)
*/
void dfs(int par,int child,vector<vector<int>> &adj,vector<int> &vis,vector<pair<int,int>> &prs,vector<vector<int>> &dp)
{
    vis[child]=true;
    for(int i=0;i<adj[child].size();i++)
    {
        int gchild=adj[child][i];
        if(!vis[gchild])
            dfs(child,gchild,adj,vis,prs,dp);
    }
    if(par!=child)
    {
        dp[par][0]+=max(dp[child][0]+abs(prs[par].first-prs[child].first),dp[child][1]+abs(prs[par].first-prs[child].second));
        dp[par][1]+=max(dp[child][0]+abs(prs[par].second-prs[child].first),dp[child][1]+abs(prs[par].second-prs[child].second));
    }
}
int32_t main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> prs(n);
        for(int i=0;i<n;i++)
            cin>>prs[i].first>>prs[i].second;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        vector<vector<int>> dp(n,vector<int>(2,0));
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        dfs(0,0,adj,vis,prs,dp);
        cout<<max(dp[0][0],dp[0][1])<<endl;
    }
}