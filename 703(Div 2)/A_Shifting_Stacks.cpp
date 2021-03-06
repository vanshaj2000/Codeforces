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
        for(int i=0;i<n;i++)
            cin>>v[i];
        if(n==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        v[1]+=v[0];
        v[0]=0;
        string ans="YES";
        for(int i=1;i<n-1;i++)
        {
            if(v[i]>v[i-1])
            {
                v[i+1]+=v[i]-i;
                v[i]=i;
            }
            else
            {
                ans="NO";
                break;
            }
        }
        if(v[n-1]>v[n-2])
            cout<<ans<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}