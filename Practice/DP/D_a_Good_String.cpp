#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 1000000007;
double eps = 1e-12;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int func(vector<vector<int>> &dp,int s,int e,int curr,string &str)
{
    if(e-s==1)
    {
        if((str[s]-'a')==curr||(str[e]-'a')==curr)
        {
            if((str[s]-'a')==curr+1||(str[e]-'a')==curr+1)
                return 0;
            else
                return 1;
        }
        else if((str[s]-'a')==curr+1||(str[e]-'a')==curr+1)
            return 1;
        else
            return 2;
    }
    int mid=(s+e)/2;
    int d1=dp[mid+1][curr]-dp[s][curr],d2=dp[e+1][curr]-dp[mid+1][curr];;
    int x1=(mid+1-s-d1)+func(dp,mid+1,e,curr+1,str);
    int x2=(mid+1-s-d2)+func(dp,s,mid,curr+1,str);
    return min(x1,x2);
}
int main()
{
    fast_cin();
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        vector<vector<int>> dp(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
                dp[i+1][j]=dp[i][j];
            dp[i+1][str[i]-'a']++;
        }
        int s=0,e=n-1,curr=0,ans=0;
        if(n==1)
        {
            if(str[0]=='a')
                cout<<ans<<endl;
            else
                cout<<++ans<<endl;
            continue;
        }
        cout<<func(dp,s,e,curr,str)<<endl;
    }
    return 0;
}