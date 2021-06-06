#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    vector<int> mas(m,0);
    for(int i=0;i<m;i++)
        mas[i]=v[i];
    int fp=0,co=0,sum=0;
    for(int i=0;i<m;i++)
        sum+=v[i],cout<<sum<<" ";
    for(int i=m;i<n;i++)
    {
        sum+=(mas[fp]+v[i]);
        cout<<sum<<" ";
        mas[fp]+=v[i];
        fp++;
        fp%=m;
    }
    return 0;
}