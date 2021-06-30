#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define double long double
#define MOD 1000000007
int32_t main()
{
    fast_cin();
    int n,U;
    double ans=-1.0;
    cin>>n>>U;
    vector<double> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n-2;i++)
    {
        int ind=upper_bound(v.begin()+i+2,v.end(),U+v[i])-v.begin();
        ind--;
        if(ind<=i+1)
            continue;
        double temp=(v[ind]-v[i+1])/(v[ind]-v[i]);
        ans=max(ans,temp);
    }
    cout<<fixed<<setprecision(20)<<ans;
}