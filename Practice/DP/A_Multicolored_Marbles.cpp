#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int memo(int curr,int prev,vector<vector<int>> &dp)
{
    int n=dp.size()-1;
    if(curr>n)
        return 1;
    if(dp[curr][prev]!=-1)
        return dp[curr][prev];
    if(prev==0)
        return dp[curr][prev]=(memo(curr+1,curr%2+1,dp)+memo(curr+1,0,dp))%MOD;
    else if((curr%2)+1==prev)
        return dp[curr][prev]=memo(curr+1,prev,dp);
    else
        return dp[curr][prev]=(memo(curr+1,prev,dp)+memo(curr+1,3-prev,dp))%MOD;
}
int32_t main()
{
    fast_cin();
    int n,sum=0,k=4;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    //cout<<(memo(1,0,dp)-1+MOD)%MOD;
    int x=-8;
    for(int i=31;i>=0;i--)
    {
        if(x&(1<<i))
            cout<<"1";
        else
            cout<<"0";
    }
    vector<pair<int,int>> v;
}