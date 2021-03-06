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
        int n;
        cin>>n;
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        int flag=0;
        n=2*n;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                cout<<v[i/2]<<" ";
            else
                cout<<v[n-(i/2)-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}