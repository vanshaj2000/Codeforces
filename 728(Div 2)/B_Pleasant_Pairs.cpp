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
        int n,ans=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++)
        {
            for(int j=v[i];(j-(i+1))<=i;j+=v[i])
            {
                if(j-(i+1)<=0)
                    continue;
                int tt=j-(i+1);
                if(v[tt-1]==(j/v[i]))
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
}