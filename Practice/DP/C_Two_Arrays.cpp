#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(2*m,1));
    for(int i=0;i<n;i++)
        dp[i][0]=i+1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<2*m;j++)
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
    }
    cout<<dp[n-1][2*m-1];
    return 0;
}