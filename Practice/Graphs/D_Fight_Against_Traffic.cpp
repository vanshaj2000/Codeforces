#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int n,m,s,t,ans=0;
    cin>>n>>m>>s>>t;
    s--,t--;
    vector<vector<int>> adj(n,vector<int>(n,0));
    vector<pair<int,int>> eds;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        eds.push_back({x-1,y-1});
        adj[x-1][y-1]=adj[y-1][x-1]=1;
    }
    vector<int> ss(n,INT_MAX),ts(n,INT_MAX);
    ss[s]=0,ts[t]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<eds.size();j++)
        {
            int x=eds[j].first,y=eds[j].second;
            if(min(ss[x],ss[y])!=max(ss[x],ss[y]))
            {
                if(ss[x]<ss[y])
                    ss[y]=ss[x]+1;
                else
                    ss[x]=ss[y]+1;
            }
            if(min(ts[x],ts[y])!=max(ts[x],ts[y]))
            {
                if(ts[x]<ts[y])
                    ts[y]=ts[x]+1;
                else
                    ts[x]=ts[y]+1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!adj[i][j])
                ans+=(((ss[i]+ts[j]+1<ss[t])||(ss[j]+ts[i]+1<ss[t]))?0:1);
        }
    }
    cout<<ans;
    return 0;
}