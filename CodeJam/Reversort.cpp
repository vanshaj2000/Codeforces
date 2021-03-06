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
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    ll t;
    cin>>t;
    int tt=0;
    while(t--)
    {
        tt++;
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int ind;
            int maxi=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(v[j]<maxi)
                {
                    ind=j;
                    maxi=v[j];
                }
            }
            ans+=ind-i+1;
            reverse(v.begin()+i,v.begin()+ind+1);
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}