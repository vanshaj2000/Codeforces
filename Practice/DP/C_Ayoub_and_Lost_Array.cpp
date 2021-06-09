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
    int n,l,r,mod=1000000007;
    cin>>n>>l>>r;
    if(l==r)
    {
        if((l%3)==0||(n%3)==0)
            cout<<"1";
        else
            cout<<"0";
        return 0;
    }
    vector<int> rem(3,0);
    if(l==r-1)
    {
        rem[l%3]++;
        rem[((l%3)+1)%3]++;
    }
    else if(l==r-2)
        rem[0]=rem[1]=rem[2]=1;
    else
    {
        if(l%3==1)
            rem[1]++,l++;
        if(l%3==2)
            rem[2]++,l++;
        if(r>l)
        {
            if(r%3==2)
                rem[2]++,r--;
            if(r%3==1)
                rem[1]++,r--;
        }
        int num=(r-l)/3;
        rem[0]+=(num+1),rem[1]+=(num),rem[2]+=(num);
    }
    //cout<<rem[0]<<" "<<rem[1]<<" "<<rem[2]<<endl;
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    dp[1][0]=rem[0],dp[1][1]=rem[1],dp[1][2]=rem[2];
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=((dp[i-1][1]*rem[2])%mod+(dp[i-1][2]*rem[1])%mod+(dp[i-1][0]*rem[0])%mod)%mod;
        dp[i][1]=((dp[i-1][1]*rem[0])%mod+(dp[i-1][2]*rem[2])%mod+(dp[i-1][0]*rem[1])%mod)%mod;
        dp[i][2]=((dp[i-1][1]*rem[1])%mod+(dp[i-1][2]*rem[0])%mod+(dp[i-1][0]*rem[2])%mod)%mod;
    }
    cout<<(dp[n][0]+mod)%mod;
    return 0;
}