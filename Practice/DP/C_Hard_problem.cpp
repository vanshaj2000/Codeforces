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
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0;i<n;i++)
        cin>>c[i];
    vector<vector<string>> v(n,vector<string>(2));
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        v[i][0]=temp;
        reverse(temp.begin(),temp.end());
        v[i][1]=temp;
    }
    vector<vector<int>> dp(n,vector<int>(2,LLONG_MAX));
    dp[0][0]=0,dp[0][1]=c[0];
    for(int i=1;i<n;i++)
    {
        if(dp[i-1][0]==LLONG_MAX&&dp[i-1][1]==LLONG_MAX)
            break;
        for(int j=0;j<2;j++)
        {
            if(dp[i-1][j]!=LLONG_MAX)
            {
                if(v[i-1][j]<=v[i][0])
                    dp[i][0]=min(dp[i][0],dp[i-1][j]);
                if(v[i-1][j]<=v[i][1])
                    dp[i][1]=min(dp[i][1],c[i]+dp[i-1][j]);
            }
        }
    }
    int ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans==LLONG_MAX)
        ans=-1;
    cout<<ans;
    return 0;
}