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
    int n,k,x,ans=0;
    cin>>n>>k>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    vector<vector<int>> gp;
    for(int i=1;i<n;i++)
    {
        if(v[i]-v[i-1]>x)
            gp.push_back({v[i]-v[i-1],i-1,i});
    }
    sort(gp.begin(),gp.end());
    map<pair<int,int>,int> mp;
    for(int i=0;i<gp.size();i++)
    {
        int req=gp[i][0]/x;
        if(gp[i][0]%x==0)
            req--;
        if(k>=req)
        {
            mp[{gp[i][1],gp[i][2]}]=1;
            k-=req;
        }
        else
            break;
    }
    for(int i=1;i<n;i++)
    {
        if(v[i]-v[i-1]>x&&(!mp[{i-1,i}]))
            ans++;
    }
    cout<<ans+1;
}