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
    int n,k;
    cin>>n>>k;
    string str,ans(k,'z');
    cin>>str;
    for(int i=1;i<=n;i++)
    {
        string temp=str.substr(0,i);
        string ch=temp;
        int req=k/i;
        for(int j=0;j<req;j++)
            ch+=temp;
        ans=min(ans,ch.substr(0,k));
    }
    cout<<ans;
}