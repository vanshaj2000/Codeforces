#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m,0));
    vector<vector<int>> dp4(n+2,vector<int>(m+2,0));
    vector<vector<int>> dp3(n+2,vector<int>(m+2,0));
    vector<vector<int>> dp2(n+2,vector<int>(m+2,0));
    vector<vector<int>> dp1(n+2,vector<int>(m+2,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>dp[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+dp[i-1][j-1];
    }
    
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
            dp2[i][j]=max(dp2[i+1][j],dp2[i][j-1])+dp[i-1][j-1];
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
            dp3[i][j]=max(dp3[i+1][j],dp3[i][j+1])+dp[i-1][j-1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
            dp4[i][j]=max(dp4[i-1][j],dp4[i][j+1])+dp[i-1][j-1];
    }
    int ans=0;
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
            ans=max(ans,max(dp1[i][j-1]+dp3[i][j+1]+dp2[i+1][j]+dp4[i-1][j],dp1[i-1][j]+dp3[i+1][j]+dp2[i][j-1]+dp4[i][j+1]));
    }
    cout<<ans;
    return 0;
}