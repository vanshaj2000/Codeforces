#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
#define int long long int
int32_t main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    if(k==1)
    {
        vector<int> xx(n,0);
        for(int i=1;i<n-1;i++)
        {
            xx[i]=xx[i-1];
            if(v[i]>v[xx[i-1]])
                xx[i]=i;
        }
        int ans=0,a,b;
        for(int i=n-1;i>=1;i--)
        {
            if(v[i]+v[xx[i-1]]>=ans)
                ans=v[i]+v[xx[i-1]],a=xx[i-1],b=i;
        }
        cout<<a+1<<" "<<b+1;
        return 0;
    }
    vector<int> dp(n,k-1);
    vector<int> sum(n+1,0);
    for(int i=0;i<n;i++)
        sum[i+1]=sum[i]+v[i];
    for(int i=k-1;i<n-k;i++)
    {
        int temp=sum[i+1]-sum[i+1-k];
        int t2=sum[dp[i-1]+1]-sum[dp[i-1]+1-k];
        dp[i]=dp[i-1];
        if(temp>t2)
            dp[i]=i;
    }
    int ans=0,a,b;
    for(int i=n-1;i>=(2*k-1);i--)
    {
        int x=dp[i-k];
        int temp=sum[i+1]-sum[i+1-k]+sum[x+1]-sum[x+1-k];
        if(temp>=ans)
            ans=temp,a=x,b=i;
    }
    cout<<a-k+2<<" "<<b-k+2;
    return 0;
}