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
        ll a,b;
        cin>>a>>b;
        if(b>a)
        {
            cout<<"1"<<endl;
            continue;
        }
        ll ans=a+3;
        //cout<<a<<" "<<b<<endl;
        for(ll i=(b<2?2-b:0);i<ans;++i)
        {
            ll at=a;
            ll temp=i;
            ll bt=b+i;
            while(at>0)
            {
                at=at/bt;
                temp++;
            }
            if(ans>temp)
                ans=temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}