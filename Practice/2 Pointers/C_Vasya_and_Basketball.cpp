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
    int n,m;
    cin>>n;
    vector<int> va(n);
    for(int i=0;i<n;i++)
        cin>>va[i];
    cin>>m;
    vector<int> vb(m);
    for(int i=0;i<m;i++)
        cin>>vb[i];
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    int ans=2*(n-m),a=2*n,b=2*m;
    for(int i=n-1;i>=0;i--)
    {
        int ind=lower_bound(vb.begin(),vb.end(),va[i])-vb.begin();
        int tb=2*(ind)+3*(m-ind),ta=2*i+3*(n-i);
        if(ta-tb>=ans)
            ans=ta-tb,a=ta,b=tb;
    }
    cout<<a<<":"<<b;
}