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
    int n,mini=1;
    cin>>n;
    vector<int> a(n),b(n),dp(n+1,0);
    vector<pair<int,int>> pr(n);
    dp[1]=1;
    for(int i=0;i<n;i++)
        cin>>pr[i].first>>pr[i].second,a[i]=pr[i].first;
    sort(pr.begin(),pr.end());
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++)
    {
        int x=pr[i].first-pr[i].second;
        int ind=lower_bound(a.begin(),a.end(),x)-a.begin();
        dp[i+1]=1+dp[ind];
        mini=max(mini,dp[i+1]);
    }
    cout<<n-mini;
}