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
        int n,fl=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int x=accumulate(v.begin(),v.end(),0);
        if(x!=0)
        {
            cout<<"YES"<<endl;
            if(x>0)
                sort(v.begin(),v.end(),greater<int>());
            else
                sort(v.begin(),v.end());
            for(int i=0;i<n;i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}