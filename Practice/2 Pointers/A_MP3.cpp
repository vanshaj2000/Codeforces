#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int32_t main()
{
    int n,I,sum=0;
    cin>>n>>I;
    vector<int> v(n),dp(n+1,0),vec;
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int curr=v[0],nn=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==curr)
            nn++;
        else
            vec.push_back(nn),curr=v[i],nn=1;
    }
    vec.push_back(nn);
    I=(8*I);
    int ans=LLONG_MAX;
    vector<int> pos;
    for(int j=0;j<vec.size();j++)
    {
        sum+=vec[j];
        dp[j+1]+=dp[j]+vec[j];
    }
    int num=vec.size();
    while(n*(ceil(log2(num)))>I)
        num--;
    //cout<<num<<endl;
    for(int i=0;i+num<=n;i++)
    {
        int temp=sum-(dp[i+num]-dp[i]);
        ans=min(ans,temp);
    }
    cout<<ans;
}