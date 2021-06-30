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
    int n,f,s,sum=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int x=v.back();
    v.pop_back();
    v.insert(v.begin(),x);
    cin>>s>>f;
    int ans=sum,time=0;
    for(int i=1;i<n;i++)
    {
        int l=(s-i+n)%n;
        int r=(f-i+n)%n;
        sum+=(v[l]-v[r]);
        if(sum>ans)
            ans=sum,time=i;
    }
    cout<<time+1;
}