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
        int n,sum=0,ans=0,temp=0,temp2=0;
        cin>>n;
        vector<int> v(n);
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        for(int i=0;i<n;i++)
            cin>>v[i],sum+=(i%2)?0:v[i];
        for(int i=0;i<n;i++)
        {
            //(dp[i]+(i%2:0:v[i]))
            dp[i+1][0]=max(dp[i+1][0],(dp[i][0]+(i%2?0:v[i])));
            if(i+2<=n)
                dp[i+2][1]=max(dp[i+2][1],max(dp[i][0],dp[i][1]))+(i%2?v[i]:v[i+1]);
            dp[i+1][2]=max(dp[i+1][2],max(dp[i][0],max(dp[i][1],dp[i][2])))+(i%2?0:v[i]);
        }
        cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
    }
    return 0;
}