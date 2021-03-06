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
    string str;
    cin>>str;
    int k;
    cin>>k;
    vector<int> v(26);
    for(int i=0;i<26;i++)
        cin>>v[i];
    ll ans=0;
    for(int i=1;i<=str.size();i++)
        ans+=v[str[i-1]-'a']*i;
    int maxi=*max_element(v.begin(),v.end());
    for(int i=1;i<=k;i++)
        ans+=maxi*(str.size()+i);
    cout<<ans;
    return 0;
}