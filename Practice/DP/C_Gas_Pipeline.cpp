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
#define int long long int
int32_t main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,ans=0,l=0,d=0;
        cin>>n>>a>>b;
        string str;
        cin>>str;
        ans+=b;
        for(int i=0;i<n-1;i++)
        {
            ans+=a+b+b*l;
            if(i==n-2)
                break;
            //cout<<ans<<endl;
            if(str[i]<str[i+1])
            {
                ans+=(((1-l)*(a+b))-(d*a));
                d=0;
                l=1;
            }
            else if(str[i]==str[i+1])
                d=0;
            else
                ans+=a,l=0,d=1;
            //cout<<ans<<endl;
        }
        ans+=(b+a+l*a);
        int ans1=ans;
        ans=b,l=0,d=0;
        for(int i=0;i<n-1;i++)
        {
            ans+=a+b+b*l;
            if(i==n-2)
                break;
            //cout<<ans<<endl;
            if(str[i]<str[i+1])
            {
                ans+=(((1-l)*(a+b))-(d*a));
                d=0;
                l=1;
            }
            else if(str[i]==str[i+1])
                d=0;
            else
                l=1,d=0;
            //cout<<ans<<endl;
        }
        ans+=(b+a+l*a);
        cout<<min(ans,ans1)<<endl;
    }
    return 0;
}