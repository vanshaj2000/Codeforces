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
        int n2;
        cin>>n2;
        string str;
        cin>>str;
        int rem=10000003;
        vector<int> pos;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='*')
                pos.push_back(i);
        }
        ll ans=0;
        int n=pos.size();
        for(int i=1;i<n;i++)
        {
            int diff=pos[i]-pos[i-1]-1;
            if(i<=n-i)
                ans=((ans)+(i*diff));
            else
                ans=((ans)+((n-i)*diff));
        }
        cout<<ans<<endl;
    }
    return 0;
}