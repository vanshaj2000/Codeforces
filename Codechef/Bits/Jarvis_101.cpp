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

ll solve(int curr,int n,string s)
{
    if(curr==n)
        return 1;
    if(s=="10")
        return solve(curr+1,n,"00")%MOD;
    else
        return ((solve(curr+1,n,{s[1],'0'}))%MOD+(solve(curr+1,n,{s[1],'1'}))%MOD)%MOD;
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        ll a1=(solve(2,n,"00"))%MOD;
        ll a2=(solve(2,n,"01"))%MOD;
        ll a3=(solve(2,n,"10"))%MOD;
        ll a4=(solve(2,n,"11"))%MOD;
        ll ans=(a1%MOD+a2%MOD+a3%MOD+a4%MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}