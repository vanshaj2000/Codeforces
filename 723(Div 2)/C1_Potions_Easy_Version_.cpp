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
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    ll curr=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        if(v>=0)
            curr+=v,ans++;
        else
        {
            if(curr+v>=0)
            {
                curr+=v;
                ans++;
                pq.push(v);
            }
            else
            {
                if(pq.size()>0)
                {
                    int x=pq.top();
                    if(x<v)
                    {
                        curr+=abs(x);
                        pq.pop();
                        pq.push(v);
                        curr+=v;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}