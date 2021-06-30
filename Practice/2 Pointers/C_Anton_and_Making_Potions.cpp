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
    int n,m,k,x,s;
    cin>>n>>m>>k;
    cin>>x>>s;
    int ans=n*x;
    vector<int> a(m),b(m),c(k),d(k);
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<k;i++)
        cin>>c[i];
    for(int i=0;i<k;i++)
        cin>>d[i];
    int i2=upper_bound(d.begin(),d.end(),s)-d.begin();
    if(i2!=0)
        ans=min(ans,(n-c[i2-1])*x);
    for(int i=0;i<m;i++)
    {
        //cout<<s-b[i]<<" ";
        if(b[i]>s)
            continue;
        int ind=upper_bound(d.begin(),d.end(),s-b[i])-d.begin();
        //cout<<ind<<endl;
        int num=0;
        if(ind!=0)
            num=c[ind-1];
        //cout<<num<<endl;
        int temp=(n-num)*a[i];
        ans=min(ans,temp);
    }
    cout<<ans;
}