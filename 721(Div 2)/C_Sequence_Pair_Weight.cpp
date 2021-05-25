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
    while(t--)
    {
        int n;
        cin>>n;
        unordered_map<ll,ll> mp;
        set<int> s;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            int v;
            cin>>v;
            ans+=(mp[v]*(n-i+1));
            mp[v]+=i;
            //s.insert(v[i]);
        }
        /*ll ans=0;
        for(auto tt=s.begin();tt!=s.end();tt++)
        {
            int te=*tt;
            vector<int> mpt=mp[te];
            for(int i=0;i<mpt.size();i++)
            {
                for(int j=i+1;j<mpt.size();j++)
                    ans+=((mpt[i]+1)*(n-mpt[j]));
            }
        }*/
        cout<<ans<<endl;
    }
    return 0;
}