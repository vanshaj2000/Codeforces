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
        ll n,W;
        cin>>n>>W;
        vector<ll> v(n);
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            mp[v[i]]++;
        }
        int ans=0;
        int curr=0;
        while(mp.size()!=0)
        {
            int flag=0;
            auto it=--mp.end();
            while(true)
            {
                if(curr+it->first<=W)
                {
                    curr+=it->first;
                    flag=1;
                    it->second--;
                    if(it->second==0)
                        mp.erase(it->first);
                    break;
                }
                if(it==mp.begin())
                    break;
                else
                    it--;
            }
            if(flag==0)
            {
                ans++;
                curr=0;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}