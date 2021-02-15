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

ll chos(ll a,ll b,ll c,ll d)
{
    vector<ll> temp={a,b,c,d};
    sort(temp.begin(),temp.end());
    return temp[1];
}
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
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> v(n,vector<ll>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>v[i][j];
        }
        ll ans=0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                ll jok=chos(v[i][j],v[i][m-1-j],v[n-1-i][j],v[n-1-i][m-1-j]);
                ans+=abs(v[i][j]-jok)+abs(v[i][m-1-j]-jok)+abs(v[n-1-i][j]-jok)+abs(v[n-1-i][m-1-j]-jok);
            }
        }
        if(m%2==1)
        {
            for(int i=0;i<n/2;i++)
                ans+=abs(v[i][m/2]-v[n-1-i][m/2]);
        }
        if(n%2==1)
        {
            for(int i=0;i<m/2;i++)
                ans+=abs(v[n/2][i]-v[n/2][m-1-i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}