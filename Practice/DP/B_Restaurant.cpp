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
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].second>>v[i].first;
    sort(v.begin(),v.end());
    int ans=0,prev=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second>prev)
            ans++,prev=v[i].first;
    }
    cout<<ans;
}