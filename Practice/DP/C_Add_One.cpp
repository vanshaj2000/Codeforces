#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int mod=1000000007;
int memo(vector<vector<int>> &ump,int curr,int num,int m)
{
    if(curr==0)
        return 1;
    if(ump[num][curr]!=0)
        return ump[num][curr];
    int ret=0;
    if(num==9)
        ret=(memo(ump,curr-1,1,m)+memo(ump,curr-1,0,m))%mod;
    else
        ret=memo(ump,curr-1,num+1,m)%mod;
    return ump[num][curr]=ret;
}
int32_t main()
{
    fast_cin();
    int t;
    cin>>t;
    int mm=200001;
    vector<vector<int>> ump(10,vector<int>(mm,0));
    for(int i=0;i<=9;i++)
        ump[i][mm-1]=memo(ump,mm-1,i,mm-1);
    while(t--)
    {
        string str;
        int m,ans=0;
        cin>>str>>m;
        for(int i=0;i<str.size();i++)
            ans=(ans+ump[str[i]-'0'][m])%mod;
        cout<<ans<<endl;
    }
    return 0;
}