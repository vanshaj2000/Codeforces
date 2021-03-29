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
        ll n;
        cin>>n;
        vector<vector<ll>> adj(n);
        vector<pair<ll,ll>> cos(n);
        for(ll i=0;i<n;i++)
        {
            cin>>cos[i].first;
            cos[i].second=i;
        }
        sort(cos.begin(),cos.end(),greater<pair<ll,ll>>());
        vector<ll> indeg(n,0);
        for(ll i=0;i<n-1;i++)
        {
            ll x,y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
            indeg[x-1]++;
            indeg[y-1]++;
        }
        ll sum=0;
        for(ll i=0;i<n;i++)
            sum+=cos[i].first;
        vector<ll> ans(n,0);
        ll k=1;
        ll j=0;
        ll curr=sum;
        ans[k]=curr;
        //cout<<"Hel"<<endl;
        //for(ll i=0;i<n;i++)
            //cout<<cos[i].first<<" "<<cos[i].second<<endl;
        while(k!=n-1)
        {
            //cout<<k<<endl;
            ll cost=cos[j].first;
            ll ind=cos[j].second;
            if(indeg[ind]>1)
            {
                curr+=cost;
                k++;
                ans[k]=curr;
                indeg[ind]--;
                // for(ll i=0;i<adj[ind].size();i++)
                //     indeg[adj[ind][i]]--;
            }
            else
                j++;
        }
        //cout<<"Hemlo"<<endl;
        for(ll i=1;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}