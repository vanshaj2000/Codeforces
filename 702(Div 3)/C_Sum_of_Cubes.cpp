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
        ll temp=cbrt(n);
        //cout<<temp<<endl;
        ll x=temp;
        ll y=1;
        string ans="NO";
        while(x>=y)
        {
            ll tt=pow(x,3)+pow(y,3);
            if(tt==n)
            {
                ans="YES";
                break;
            }
            else if(tt<n)
                y++;
            else
                x--;
        }
        cout<<ans<<endl;
    }
    return 0;
}