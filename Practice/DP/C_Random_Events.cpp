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
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main()
{
    fast_cin();
    ll t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int j;
        for(j=n-1;j>=0;j--)
        {
            //cout<<v[j]<<" "<<j+1<<endl;
            if(v[j]!=j+1)
                break;
        }
        j++;
        //cout<<j<<endl;
        double ans=1;
        for(int i=0;i<m;i++)
        {
            int x;
            double y;
            cin>>x>>y;
            if(x>=j)
                ans*=(1-y);
        }
        if(j==0)
        {
            ans=1;
            cout<<fixed<<setprecision(6)<<ans<<endl;
            continue;
        }
        cout<<fixed<<setprecision(6)<<(1.000000-ans)<<endl;
    }
    return 0;
}