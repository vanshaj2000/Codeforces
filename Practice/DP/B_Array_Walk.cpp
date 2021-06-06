#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,z,ans=0;
        cin>>n>>k>>z;
        vector<int> v(n),sum(n+1,0);
        for(int i=0;i<n;i++)
            cin>>v[i],sum[i+1]+=(sum[i]+v[i]);
        vector<int> dp(n,0);
        for(int i=1;i<n;i++)
            dp[i]=max(dp[i-1],v[i]+v[i-1]);
        for(int i=0;((i<=z)&&((k-2*i)>=0));i++)
            ans=max(ans,sum[k+1-2*i]+(i*(dp[k+1-2*i])));
        cout<<ans<<endl;
    }
    return 0;
}