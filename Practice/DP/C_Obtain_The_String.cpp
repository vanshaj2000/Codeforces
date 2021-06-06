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
        string s,t;
        cin>>s>>t;
        int n=s.size(),curr=0,ans=1;
        vector<int> vis1(26,0);
        vector<vector<int>> dp(n+1,vector<int>(26,-1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
                dp[i][j]=dp[i+1][j];
            dp[i][s[i]-'a']=i;
            vis1[s[i]-'a']=1;
        }
        for(int i=0;i<t.size();i++)
        {
            if(!vis1[t[i]-'a'])
            {
                ans=-1;
                break;
            }
            if(curr>=n||dp[curr][t[i]-'a']==-1)
                curr=0,ans++,i--;
            else
                curr=dp[curr][t[i]-'a']+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}