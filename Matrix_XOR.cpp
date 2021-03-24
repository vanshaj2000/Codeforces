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
        int n,m,k;
        cin>>n>>m>>k;
        int n2=n,m2=m;
        n=min(n2,m2);
        m=max(n2,m2);
        n2=n;
        m2=m;
        int ans=0;
        while(n>0)
        {
            if(n==1)
            {
                for(int i=1;i<=m2;i++)
                    ans^=k+n2+i;
                n--;
            }
            else
            {
                ans^=k+n2-n+1+1;
                ans^=k+n2-n+1+1+m2;
                n=n-2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}