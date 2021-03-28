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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,T;
        cin>>n>>T;
        vector<pair<ll,ll>> v(n);
        for(ll i=0;i<n;i++)
        {
            cin>>v[i].first;
            v[i].second=i;
        }
        vector<ll> ans(n,0);
        sort(v.begin(),v.end());
        for(ll i=n-1;i>0;i--) 
        {
            if(v[i].first+v[i-1].first>T)
                ans[v[i].second]=1;
            else if(v[i].first+v[i-1].first<T)
            {
                ans[v[i].second]=0;
                ans[v[i-1].second]=0;
            }
            else
            {
                ans[v[i].second]=1;
                ans[v[i-1].second]=0;
                i--;
            }
        }
        for(ll i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}