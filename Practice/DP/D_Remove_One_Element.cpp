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
#define int long long int
int32_t main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<vector<int>> dp(n,vector<int>(2,1));
    dp[1][0]=(v[0]<v[1])?2:1;
    for(int i=2;i<n;i++)
    {
        if(v[i]>v[i-1])
        {
            dp[i][0]=1+dp[i-1][0];
            dp[i][1]=dp[i-1][1]+1;
        }
        if(v[i]>v[i-2])
            dp[i][1]=max(1+dp[i-2][0],dp[i][1]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,max(dp[i][0],dp[i][1]));
    cout<<ans;
    return 0;
}