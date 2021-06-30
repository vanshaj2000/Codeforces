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
    int n,q;
    cin>>n;
    string str;
    cin>>str;
    cin>>q;
    vector<vector<int>> dp(n+1,vector<int>(26,0));
    for(int k=0;k<26;k++)
    {
        for(int i=0;i<n;i++)
        {
            int x=0;
            for(int j=i;j<n;j++)
            {
                if((str[j]-'a')!=k)
                    x++;
                dp[x][k]=max(dp[x][k],j-i+1);
            }
        }
        for(int i=1;i<=n;i++)
            dp[i][k]=max(dp[i-1][k],dp[i][k]);
    }
    for(int i=0;i<q;i++)
    {
        int x;
        char ch;
        cin>>x;
        cin>>ch;
        //cout<<ch<<endl;
        cout<<dp[x][ch-'a']<<endl;
    }
    return 0;
}