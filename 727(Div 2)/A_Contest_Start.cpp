#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int32_t main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,t;
        cin>>n>>x>>t;
        int r=t/x;
        r=min(n,r);
        int ans=((n-r)*(r));
        if(r%2==0)
            ans+=(r/2)*(r-1);
        else
            ans+=((r-1)/2)*r;
        cout<<ans<<endl;
    }
}