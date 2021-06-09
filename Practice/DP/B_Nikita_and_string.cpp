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

int main()
{
    fast_cin();
    string str;
    cin>>str;
    int n=str.size(),ans=0;
    //cout<<"Hem"<<endl;
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=1;i<=n;i++)
        dp[i]=dp[i-1],dp[i][str[i-1]-'a']++;
    for(int i=0;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int a=dp[i][0],b=dp[j][1]-dp[i][1],c=dp[n][0]-dp[j][0];
            ans=max(ans,a+b+c);
        }
    }
    cout<<ans;
    return 0;
}