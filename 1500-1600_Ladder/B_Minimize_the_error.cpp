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

bool csort(int a,int b)
{
    return pow(a,2)<pow(b,2);
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    ll n,k1,k2;
    cin>>n>>k1>>k2;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    vector<ll> diff(n);
    for(int i=0;i<n;i++)
        diff[i]=abs(a[i]-b[i]);
    priority_queue<ll> pq;
    for(int i=0;i<n;i++)
        pq.push(diff[i]);
    ll k=k1+k2;
    while(k>0)
    {
        ll temp=pq.top();
        pq.pop();
        temp--;
        pq.push(abs(temp));
        k--;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=pow(pq.top(),2);
        pq.pop();
    }
    cout<<ans;
    return 0;
}