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
        vector<ll> v(n);
        int r[3];
        r[0]=0;
        r[1]=0;
        r[2]=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            r[v[i]%3]++;
        }
        int ans=0;
        int req=n/3;
        if(r[2]<req)
        {
            r[1]=r[1]-(req-r[2]);
            ans=ans+req-r[2];
        }
        else
        {
            r[0]=r[0]+r[2]-req;
            ans+=r[2]-req;
        }
        if(r[1]<0)
        {
            ans+=abs(r[1]);
            r[0]+=r[1];
            r[1]=0;
        }
        if(r[0]<req)
            ans+=(req-r[0])*2;
        else
            ans+=abs(req-r[0]);
        cout<<ans<<endl;
    }
    return 0;
}