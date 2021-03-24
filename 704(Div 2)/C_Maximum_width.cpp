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
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s;
    cin>>t;
    int k=0;
    int ans=0;
    vector<int> pos(m);
    int k2=m-1;
    for(int i=n-1;i>=0&&k2>=0;i--)
    {
        if(s[i]==t[k2])
        {
            pos[k2]=i;
            k2--;
        }
    }
    for(int i=0;i<n&&k<(m-1);i++)
    {
        if(s[i]==t[k])
        {
            ans=max(ans,pos[k+1]-i);
            k++;
        }
    }
    cout<<ans;
    return 0;
}