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

bool cuss(pair<int,int> &p1,pair<int,int> &p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;
    else
        return p1.first>p2.first;
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first;
            v[i].second=i;
        }
        sort(v.begin(),v.end(),cuss);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[v[i].second]=i+1;
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}