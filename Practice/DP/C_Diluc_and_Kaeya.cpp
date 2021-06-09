#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
        int n;
        cin>>n;
        string str;
        cin>>str;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='D')
                str[i]='0';
            else
                str[i]='1';
        }
        vector<vector<int>> nums(n+1,vector<int>(2,0));
        for(int i=1;i<=n;i++)
            nums[i]=nums[i-1],nums[i][str[i-1]-'0']++;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            if(dp[i]!=1)
                continue;
            int a=nums[i+1][0],b=nums[i+1][1],c=2,gc=__gcd(a,b);
            a=a/gc,b=b/gc;
            int d=a+b,s=i+1,e=i+d;
            while(s<n&&e<n)
            {
                int a2=nums[e+1][0]-nums[s][0],b2=nums[e+1][1]-nums[s][1];
                if((a*b2)==(b*a2))
                {
                    dp[e]=max(dp[e],c),c++;
                    s=e+1,e=s+d-1;
                }
                else
                    e+=d;
            }
        }
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";
        cout<<endl;
    }
    return 0;
}