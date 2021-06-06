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
        int n,p,k,ans=0;
        cin>>n>>p>>k;
        vector<int> v(n),dp(n+1,0);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
            dp[i+1]=dp[i]+v[i];
        for(int i=0;i<=k;i++)
        {
            int tp=p-dp[i],count=((tp>=0)?i:0);
            for(int j=i+k-1;j<n;j+=k)
            {
                if(tp>=v[j])
                    count+=k,tp-=v[j];
                else
                    break;
            }
            ans=max(ans,count);
        }
        cout<<ans<<endl;
    }
    return 0;
}