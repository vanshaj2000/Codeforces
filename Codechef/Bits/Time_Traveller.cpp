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

int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int n,k,m;
    cin>>n;
    cin>>k;
    vector<vector<int>> tup(k,vector<int>(3));
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<k;i++)
    {
        cin>>tup[i][0]>>tup[i][1]>>tup[i][2];
        adj[tup[i][2]].push_back({tup[i][0],tup[i][1]});
    }
    cin>>m;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int t=adj[i][j].first,p=adj[i][j].second;
            if(t>=i+1)
                ans.push_back(p);
        }
    }
    sort(ans.begin(),ans.end());
    int cc=0;
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(i<=m)
            cc+=ans[i];
    }
    cout<<cc;
    return 0;
}