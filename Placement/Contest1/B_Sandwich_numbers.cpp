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
    int n,fl=0;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    pair<int,int> inter;
    if(a[0]>b[0])
    {
        cout<<"0";
        return 0;
    }
    inter={a[0],b[0]};
    for(int i=1;i<n;i++)
    {
        if(a[i]>b[i])
        {
            fl++;
            break;
        }
        if(b[i]<inter.first||a[i]>inter.second)
        {
            fl++;
            break;
        }
        else
            inter.first=max(a[i],inter.first),inter.second=min(b[i],inter.second);
    }
    if(fl)
        cout<<"0";
    else
        cout<<inter.second-inter.first+1;
    return 0;
}