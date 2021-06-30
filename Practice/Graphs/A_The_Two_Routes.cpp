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

int dfs(vector<vector<int>> &adj,vector<int> &vis)
{
    int n=adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(n,INT_MAX);
    dis[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int t=pq.top().second,d=pq.top().first;
        pq.pop();
        if(vis[t])
            continue;
        vis[t]=1;
        for(int i=0;i<adj[t].size();i++)
        {
            if(dis[adj[t][i]]>1+dis[t])
            {
                dis[adj[t][i]]=1+dis[t];
                pq.push({dis[adj[t][i]],adj[t][i]});
            }
        }
    }
    return dis[n-1];
}

int main()
{
    fast_cin();
    int flag=0,n,m;
    cin>>n>>m;
    vector<int> vis1(n,0),vis2(n,0);
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
            if(vis[i][j]==2)
            {
                adjBus[i].push_back(j);
                adjBus[j].push_back(i);
                vis[i][j]=vis[j][i]=0;   
            }
        }
    }
    int mini1=dfs(adj,vis1),mini2=dfs(adjBus,vis2);
    int ans=max(mini1,mini2);
    if(ans==INT_MAX)
        cout<<"-1";
    else
        cout<<ans;
    //cout<<((max(mini1,mini2)==INT_MAX)?"-1":max(mini1,mini2));
    return 0;
}