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
        ll n;
        cin>>n;
        vector<ll> x(n);
        vector<ll> y(n);
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        ll xf=0;
        ll yf=0;
        int c1=(n-1)/2;
        int c2=(n)/2;
        xf=x[c2]-x[c1]+1;
        yf=y[c2]-y[c1]+1;
        cout<<xf*yf<<endl;
    }
    return 0;
}