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
    ll n;
    cin>>n;
    vector<ll> v(n);
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        c=(v[i]==1)?c+1:c+0;
    }
    if(c>0)
        cout<<n-c;
    else
    {
        int mini=4001;
        for(int i=0;i<n;i++)
        {
            ll temp=v[i];
            for(int j=i+1;j<n;j++)
            {
                temp=__gcd(temp,v[j]);
                if(temp==1)
                {
                    int t=j-i;
                    mini=min(t,mini);
                    break;
                }
            }
        }
        if(mini!=4001)
            cout<<n-1+mini;
        else
            cout<<"-1";
    }
    return 0;
}