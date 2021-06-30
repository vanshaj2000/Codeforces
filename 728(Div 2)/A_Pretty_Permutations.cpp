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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            v[i]=i+1;
        for(int i=1;i<n;i+=2)
            swap(v[i],v[i-1]);
        if(n%2==1)
            swap(v[n-1],v[n-2]);
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}