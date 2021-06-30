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
        int n,ans=0,maxi=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin()+1,v.end());
        int curr=0;
        for(int i=1;i<n;i++)
        {
            ans+=(v[i]*(i)-curr);
            curr+=v[i];
        }
        ans-=v[n-1];
        cout<<-1*ans<<endl;
    }
}