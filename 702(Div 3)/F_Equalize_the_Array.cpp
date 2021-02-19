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
        //cout<<"Hello"<<endl;
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        vector<ll> num;
        num.push_back(1);
        for(int i=1;i<n;i++)
        {
            if(v[i]==v[i-1])
                num[num.size()-1]++;
            else
                num.push_back(1);
        }
        // for(int i=0;i<num.size();i++)
        //     cout<<num[i]<<endl;
        sort(num.begin(),num.end());
        vector<ll> presum(num.size());
        presum[0]=num[0];
        for(int i=1;i<num.size();i++)
            presum[i]=num[i]+presum[i-1];
        ll ans=INT_MAX;
        int nn=num.size();
        for(int i=0;i<=num[nn-1];i++)
        {
            auto it=lower_bound(num.begin(),num.end(),i);
            int l=it-num.begin();
            ll sum=0;
            if(l>0)
            {
                sum+=(presum[l-1]);
                sum+=presum[nn-1]-presum[l-1]-i*(nn-l);
            }
            else
                sum+=presum[nn-1]-(nn)*i;
            ans=min(sum,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}