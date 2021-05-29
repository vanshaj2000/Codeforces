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
bool dfs(int ind,vector<pair<int,int>> &adj,int tar,vector<bool> &vis)
{
    vis[ind]=true;
    if(ind==tar)
        return true;
    bool ans=false;
    for(int i=0;i<adj.size();i++)
    {
        if(i!=ind)
        {
            int t1=adj[i].first,t2=adj[i].second,m1=adj[ind].first,m2=adj[ind].second;
            if((m1>t1&&m1<t2)||(m2>t1&&m2<t2))
            {
                if(!vis[i])
                    ans=ans||dfs(i,adj,tar,vis);
            }
        }
    }
    return ans;
}
int main()
{
    fast_cin();
    vector<pair<int,int>> eds;
    int m;
    cin>>m;
    for(int l=0;l<m;l++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1)
            eds.push_back({y,z});
        else
        {
            vector<bool> vis(eds.size(),false);
            if(dfs(y-1,eds,z-1,vis))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}