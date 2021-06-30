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
    int n,x=0,ans=0;
    cin>>n;
    vector<int> v(n);
    vector<unordered_map<int,int>> ump(2);
    ump[1][0]=1;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
    {
        x^=v[i];
        ans+=ump[i%2][x];
        ump[i%2][x]++;
    }
    cout<<ans;
    return 0;
}