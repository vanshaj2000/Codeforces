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
        int n;
        cin>>n;
        vector<ll> b(n+2);
        for(int i=0;i<n+2;i++)
            cin>>b[i];
        sort(b.begin(),b.end());
        ll c1=b[n];
        ll c2=b[n+1];
        ll sum=0;
        for(int i=0;i<n;i++)
            sum+=b[i];
        ll sum2=0;
        for(int i=0;i<n+1;i++)
            sum2+=b[i];
        if(sum==c1)
        {
            for(int i=0;i<n;i++)
                cout<<b[i]<<" ";
            cout<<endl;
        }
        else
        {
            int ind=-1;
            for(int i=0;i<n+1;i++)
            {
                if(sum2-b[i]==c2)
                {
                    ind=i;
                    break;
                }
            }
            if(ind==-1)
                cout<<"-1"<<endl;
            else
            {
                for(int i=0;i<n+1;i++)
                {
                    if(i!=ind)
                        cout<<b[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}