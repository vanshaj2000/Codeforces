#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int recur(vector<vector<int>> &dp,int n,int k)
{
    if(n==0||k==0||n==k)
        return 1;
    if(dp[n][k]!=-1)
        return dp[n][k];
    return dp[n][k]=recur(dp,n-1,k)+recur(dp,n-1,k-1);
}
int32_t main()
{
    fast_cin();
    int n,k,ans=0;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    for(int i=2;i<=k;i++)
    {
        if(i==2)
            ans+=(n*(n-1))/2;
        else if(i==3)
            ans+=2*recur(dp,n,3);
        else if(i==4)
            ans+=9*recur(dp,n,4);
    }
    cout<<ans+1;
    return 0;
}