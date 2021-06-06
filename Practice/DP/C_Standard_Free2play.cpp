#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int n,h;
        cin>>h>>n;
        int vis[n],dp[n];
        dp[0]=0;
        for(int i=0;i<n;i++)
            cin>>vis[i];
        if(h==1||n==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        int ans=0;
        dp[1]=1;
        for(int i=2;i<n;i++)
        {
            dp[i]=dp[i-1]+1;
            if(vis[i-1]-vis[i]==1)
                dp[i]=min(dp[i-2],dp[i]);
        }
        if(vis[n-1]==1)
        {
            if(vis[n-2]==2)
                cout<<min(dp[n-2],dp[n-1])<<endl;
            else
                cout<<dp[n-1]-1<<endl;
        }
        else
            cout<<dp[n-1]<<endl;
    }
    return 0;
}