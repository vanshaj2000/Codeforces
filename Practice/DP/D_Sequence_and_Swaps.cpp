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
        int n,ans=0,m=0,x,j=0;
        cin>>n>>x;
        vector<int> v(n),dp(n,0);
        for(int i=0;i<n;i++)
            cin>>v[i],m=max(m,v[i]);
        dp[n-1]=(v[n-1]==m)?1:0;
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]<=v[i+1]&&dp[i+1])
                dp[i]=1;
            else
                break;
        }
        if(dp[0]==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==1)
                break;
            else
            {
                if(x<v[i])
                    swap(x,v[i]),ans++;
            }
        }
        for(j=0;j<n-1;j++)
        {
            if(v[j]>v[j+1])
                break;
        }
        if(j==n-1)
            cout<<ans<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}