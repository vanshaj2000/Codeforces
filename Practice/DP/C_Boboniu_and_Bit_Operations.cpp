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
    int n,m,ans=0;
    cin>>n>>m;
    vector<int> va(n),vb(m);
    for(int i=0;i<n;i++)
        cin>>va[i];
    for(int i=0;i<m;i++)
        cin>>vb[i];
    for(int k=0;k<(1<<9);k++)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((k|(va[i]&vb[j]))==k)
                {
                    flag++;
                    break;
                }
            }
        }
        if(flag==n)
        {
            ans=k;
            break;
        }
    }
    cout<<ans;
    return 0;
}