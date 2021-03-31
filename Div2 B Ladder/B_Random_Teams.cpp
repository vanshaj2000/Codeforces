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
    ll n,m;
    cin>>n>>m;
    ll maxi=((n-m+1)*(n-m))/2;
    ll mini;
    if(m>=n)
        mini=0;
    else
    {
        ll rem=n%m;
        ll q=n/m;
        mini=rem*((q+1)*q)/2;
        mini+=((m-rem)*q*(q-1))/2;
    }
    cout<<mini<<" "<<maxi;
    return 0;
}