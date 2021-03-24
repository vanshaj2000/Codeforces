//COPIED
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        vector<int> v(n,0);
        for(int j=0;j<n;j++)
        {
            cin>>v[j];
            --v[j];
        }
        int inf=INT_MAX/2;
        sort(v.begin(),v.end());
        int c=2*n;
        vector<vector<int>> dp(n+1,vector<int>(c,inf));
        dp[0][0]=0;
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<c-1;k++)
            {
                if(dp[j][k]<inf)
                {
                    if (j<n)
                    {
                        dp[j+1][k+1] = min(dp[j+1][k+1],dp[j][k]+abs(v[j]-k));
                    }
                     dp[j][k+1]=min(dp[j][k+1],dp[j][k]);
                }
            }
        }
        cout<<dp[n][c-1]<<endl;
    }
    return 0;
}