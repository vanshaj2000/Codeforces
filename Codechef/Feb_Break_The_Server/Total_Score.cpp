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
        int n,k;
        cin>>n>>k;
        vector<ll> pro(k);
        for(int i=0;i<k;i++)
            cin>>pro[i];
        vector<string> val(n);
        for(int i=0;i<n;i++)
            cin>>val[i];
        for(int i=0;i<n;i++)
        {
            ll ans=0;
            for(int j=0;j<k;j++)
                ans+=(val[i][j]-'0')*pro[j];
            cout<<ans<<endl;
        }
    }
    return 0;
}