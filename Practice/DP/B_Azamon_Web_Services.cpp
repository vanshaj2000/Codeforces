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
    int t;
    cin>>t;
    while(t--)
    {
        string s,c;
        cin>>s>>c;
        int n=s.size(),f=0;
        vector<int> dp(n+1,n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<s[dp[i+1]])
                dp[i]=i;
            else
                dp[i]=dp[i+1];
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]>s[dp[i+1]])
            {
                swap(s[i],s[dp[i+1]]);
                break;
            }
        }
        if(s<c)
            cout<<s<<endl;
        else
            cout<<"---"<<endl;
    }
    return 0;
}