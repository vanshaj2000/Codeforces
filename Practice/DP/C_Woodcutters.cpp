#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    if(n<=2)
    {
        cout<<n;
        return 0;
    }
    vector<vector<int>> dp(n,vector<int>(2,0));
    dp[0][0]=1;
    if((v[1].first-v[0].first)>v[0].second)
        dp[0][1]=1;
    for(int i=1;i<n-1;i++)
    {
        if((v[i].first-v[i-1].first)>(v[i].second+v[i-1].second))
            dp[i][0]=1+dp[i-1][1];
        else if((v[i].first-v[i-1].first)>v[i].second)
            dp[i][0]=1+dp[i-1][0];
        else
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
        if((v[i+1].first-v[i].first)>v[i].second)
            dp[i][1]++;
    }
    cout<<1+max(dp[n-2][0],dp[n-2][1]);
    return 0;
}