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
    int n,curr=INT_MIN,curr2=INT_MIN,ans=INT_MIN;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int> v1(n-1);
    for(int i=0;i<n-1;i++)
        v1[i]=abs(v[i]-v[i+1])*pow(-1,i);
    for(int i=0;i<n-1;i++)
    {
        if((i%2)==0)
        {
            curr=max(curr+v1[i],v1[i]);
            curr2-=v1[i];
        }
        else
        {
            curr+=v1[i];
            curr2=max(curr2-v1[i],-1*v1[i]);
        }
        ans=max(ans,max(curr,curr2));
    }
    cout<<ans;
    return 0;
}