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
        vector<int> v(n),odd,eve;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if((v[i]%2)==1)
                odd.push_back(v[i]);
            else
                eve.push_back(v[i]);
        }
        int x=eve.size(),y=odd.size();
        int ans=((x*(x-1))/2)+(x*y);
        //cout<<ans<<endl;
        for(int i=0;i<y;i++)
        {
            for(int j=i+1;j<y;j++)
            {
                if(__gcd(odd[i],odd[j])>1)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
}