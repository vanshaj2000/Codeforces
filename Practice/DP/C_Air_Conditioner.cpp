#include <bits/stdc++.h>  
using namespace std;
#define int long long int
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int32_t main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int flag=0;
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int>(3));
        for(int i=0;i<n;i++)
            cin>>v[i][0]>>v[i][1]>>v[i][2];
        int curr=v[0][0];
        vector<vector<int>> dp;
        int cmin=INT_MIN,cmax=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(curr==v[i][0])
            {
                if(cmin>v[i][2]||cmax<v[i][1])
                {
                    flag++;
                    break;
                }
                cmin=max(cmin,v[i][1]);
                cmax=min(v[i][2],cmax);
            }
            else
            {
                dp.push_back({curr,cmin,cmax});
                curr=v[i][0],cmin=v[i][1],cmax=v[i][2];
            }
        }
        dp.push_back({curr,cmin,cmax});
        //for(int i=0;i<dp.size();i++)
            //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        if(flag)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int chtemp=m,cltemp=m,ctime=0;
        for(int i=0;i<dp.size();i++)
        {
            int diff=dp[i][0]-ctime;
            cltemp-=diff;
            chtemp+=diff;
            if(cltemp>dp[i][2]||chtemp<dp[i][1])
            {
                flag++;
                break;
            }
            cltemp=max(cltemp,dp[i][1]);
            chtemp=min(chtemp,dp[i][2]);
            ctime=dp[i][0];
        }
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}