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
    fast_cin();
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int j=3;j<=n;j++)
    {
        if(n%j!=0)
            continue;
        vector<int> dp(n,0);
        int gap=(n-j)/j;
        for(int i=0;i<n;i++)
        {
            if(i<=gap)
                dp[i]=v[i];
            else
            {
                dp[i]=dp[i-gap-1]+v[i];
                if(dp[i]==j)
                {
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}