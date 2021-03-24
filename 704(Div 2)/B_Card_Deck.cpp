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
int g;
bool cusS(int a,int b)
{
    return (g*a+b)/(g*b+a)>1;
}
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
        g=n;
        vector<ll> v(n);
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            pq.push(v[i]);
        }
        reverse(v.begin(),v.end());
        vector<int> nw;
        //int s=0;
        vector<vector<int>> dp;
        int maxi=INT_MIN;
        vector<int> c(n);
        for(int i=n-1;i>=0;i--)
        {
            int x=v[i];
            maxi=max(maxi,x);
            c[i]=max(maxi,x);
        }
        // for(int i=0;i<n;i++)
        //     cout<<c[i]<<" ";
        //cout<<endl;
        int s=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==c[s])
            {
                nw.push_back(v[i]);
                dp.push_back(nw);
                nw.clear();
                s=i+1;
            }
            else
                nw.push_back(v[i]);
        }
        //reverse(nw.begin(),nw.end());
        //cout<<dp.size()<<endl;
        for(int i=0;i<dp.size();i++)
        {
            for(int j=dp[i].size()-1;j>=0;j--)
                 cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}