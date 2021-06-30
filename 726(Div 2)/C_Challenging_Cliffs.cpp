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
        int n,mini=INT_MAX,f=1;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++)
            mini=min(mini,v[i+1]-v[i]);
        vector<int> ans;
        int a,b;
        for(int i=0;i<n-1;i++)
        {
            if(v[i+1]-v[i]==mini)
            {
                a=i,b=i+1;
                break;
            }
        }
        //cout<<"He"<<endl;
        cout<<v[a];
        for(int i=b+1;i<n;i++)
            cout<<" "<<v[i];
        for(int i=0;i<a;i++)
            cout<<" "<<v[i];
        cout<<" "<<v[b]<<endl;
    }
}