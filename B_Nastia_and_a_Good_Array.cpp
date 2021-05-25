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
        ll mini=INT_MAX;
        int ind;
        for(int i=0;i<n;i++)
        {
            if(v[i]<mini)
            {
                ind=i;
                mini=v[i];
            }
        }
        if(ind!=0)
        {
            cout<<n<<endl;
            cout<<1<<" "<<ind+1<<" "<<v[ind]<<" "<<v[0]<<endl;
        }
        else
            cout<<n-1<<endl;
        for(int i=1;i<n;i++)
        {
            if(i%2==0)
                cout<<i<<" "<<i+1<<" "<<1000000009<<" "<<mini<<endl;
            else
                cout<<i<<" "<<i+1<<" "<<1000000007<<" "<<mini<<endl;
        }
    }
    return 0;
}