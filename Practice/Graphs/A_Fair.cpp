#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    vector<vector<int>> gg(k);
    int gud[n][k];
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        gud[i][x-1]=0;
        gg[x-1].push_back(i);
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int j=0;j<k;j++)
    {
        queue<int> q;
        for(int i=0;i<gg[j].size();i++)
            q.push(gg[j][i]);
        vector<int> d(n,INT_MAX);
        for(int i=0;i<gg[j].size();i++)
            d[gg[j][i]]=0;
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(int i=0;i<adj[v].size();i++)
            {
                int u=adj[v][i];
                if(d[v]+1<d[u])
                {
                    d[u]=d[v]+1;
                    q.push(u);
                }
            }
        }
        for(int i=0;i<n;i++)
            gud[i][j]=d[i];
    }
    for(int i=0;i<n;i++)
    {
        nth_element(gud[i],gud[i]+s,gud[i]+k);
        int ans=0;
        for(int j=0;j<s;j++)
            ans+=gud[i][j];
        cout<<ans<<" ";
    }
    return 0;
}