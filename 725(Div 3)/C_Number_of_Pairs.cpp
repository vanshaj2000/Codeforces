#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 1000000007;
double eps = 1e-12;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r,ans=0;
        cin>>n>>l>>r;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++)
        {
            if(v[i]>=r)
                break;
            if(v[i]<l)
            {
                int indl=lower_bound(v.begin()+i+1,v.end(),l-v[i])-v.begin(),indr=upper_bound(v.begin()+i+1,v.end(),r-v[i])-v.begin();
                if(indl==n)
                    continue;
                //cout<<"Hell"<<endl;
                int req=indr-indl;
                //cout<<i<<" "<<req<<endl;
                ans+=req;
            }
            else
            {
                int indr=upper_bound(v.begin()+i+1,v.end(),r-v[i])-v.begin();
                indr--;
                int req=indr-i;
                //cout<<i<<" "<<req<<endl;
                ans+=req;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}