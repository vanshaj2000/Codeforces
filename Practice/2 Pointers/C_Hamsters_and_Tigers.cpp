#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
int32_t main()
{
    int n,ans=INT_MAX;
    cin>>n;
    string str;
    cin>>str;
    unordered_map<char,int> ump;
    ump['H']=0,ump['T']=1;
    vector<vector<int>> vp(n+1,vector<int>(2,0));
    for(int i=0;i<n;i++)
        vp[i+1]=vp[i],vp[i+1][ump[str[i]]]++;
    for(int i=0;i<2;i++)
    {
        int diff=vp[n][i];
        for(int j=0;j<n;j++)
        {
            int temp;
            if(j+diff-1>=n)
            {
                int x=n-j;
                int x2=diff-x;
                temp=vp[n][1-i]-vp[j][1-i]+vp[x2][1-i];
            }
            else
                temp=vp[j+diff][1-i]-vp[j][1-i];
            ans=min(ans,temp);
        }
    }
    cout<<ans;
}