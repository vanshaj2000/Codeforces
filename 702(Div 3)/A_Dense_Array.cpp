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
        int ans=0;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n-1;i++)
        {
            int mini=min(v[i],v[i+1]);
            int maxi=max(v[i],v[i+1]);
            if(2*mini<maxi)
            {
                while(maxi>2*mini)
                {
                    maxi=maxi/2+maxi%2;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}