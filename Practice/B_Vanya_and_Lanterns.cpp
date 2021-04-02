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
    int n,l;
    cin>>n>>l;
    vector<double> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    double ans=-1;
    v.insert(v.begin(),0);
    v.push_back(l);
    for(int i=1;i<=n;i++)
    {
        double temp=v[i]-v[i-1],temp2;
        if(i!=n)
            temp2=(v[i+1]-v[i])/2;
        else
            temp2=v[i+1]-v[i];
        temp=max(temp,temp2);
        ans=max(temp,ans);
        v[i]+=ans;
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}