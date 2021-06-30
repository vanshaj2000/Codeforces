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
    vector<int> v(n),dp(n+1,2),sum(n+1,0);
    sum[1]=2;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
    {
        dp[i+1]=(2+(sum[i]-sum[v[i]-1])%MOD)%MOD;
        sum[i+1]=(sum[i]+dp[i+1])%MOD;
    }
    cout<<(sum[n]+MOD)%MOD;
}