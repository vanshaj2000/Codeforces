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
        priority_queue<int,vector<int>,greater<int>> m;
        priority_queue<int,vector<int>,greater<int>> d;
        for(int i=0;i<2*n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x==0)
                m.push(abs(y));
            else
                d.push(abs(x));
        }
        long double sum=0;
        for(int i=0;i<n;i++)
        {
            double c1=m.top();
            double c2=d.top();
            m.pop();
            d.pop();
            sum+=sqrtl(pow(c1,2)+pow(c2,2));
        }
        cout<<fixed<<setprecision(15)<<sum<<endl;
    }
    return 0;
}