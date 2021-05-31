#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int32_t main()
{
    fast_cin();
    int n,sum=1,diff=1,mod=1000000007;
    cin>>n;
    for(int i=1;i<=n;i++)
        sum=sum*i,sum=sum%mod;
    for(int i=0;i<n-1;i++)
        diff=(diff+diff)%mod;
    cout<<((sum-diff+mod)%mod);
}