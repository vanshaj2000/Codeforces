#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int main()
{
    fast_cin();
    int q;
    cin>>q;
    while(q--)
    {
        //cout<<(-1%3)<<endl;
        int n,k,ans=INT_MAX;
        cin>>n>>k;
        string str;
        cin>>str;
        unordered_map<char,int> ump;
        ump['R']=0,ump['G']=1,ump['B']=2;
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            int x=ump[str[i]];
            int y=(x+1)%3,z=(x+2)%3;
            dp[i+1][x]=dp[i][z];
            dp[i+1][y]=1+dp[i][x];
            dp[i+1][z]=1+dp[i][y];
            //cout<<dp[i+1][x]<<" "<<dp[i+1][y]<<" "<<dp[i+1][z]<<endl;
        }
        //cout<<dp[5][0]<<endl;
        for(int i=0;i+k<=n;i++)
        {
            int x=(2*k)%3,y=(1+2*k)%3,z=(2+2*k)%3;
            //cout<<x<<" "<<y<<" "<<z<<endl;
            int a1=dp[i+k][0]-dp[i][x];
            int a2=dp[i+k][1]-dp[i][y];
            int a3=dp[i+k][2]-dp[i][z];
            //cout<<a1<<" "<<a2<<" "<<a3<<endl;
            ans=min(ans,min(a1,min(a2,a3)));
        }
        cout<<ans<<endl;
    }
    return 0;
}