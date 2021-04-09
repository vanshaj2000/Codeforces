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
vector<bool> pp(ll n)
{
    vector<bool> prime(n+1,true);
    for (ll p=2;p*p<=n;p++)
    {
        if (prime[p]==true)
        {
            for (int i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
    return prime;
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<bool> prime=pp(1000000);
    prime[1]=false;
    for(int i=0;i<n;i++)
    {
        ll ch=v[i];
        double t1=sqrt(ch);
        int tt=sqrt(ch);
        double t2=tt;
        //cout<<t1<<" "<<t2;
        if(t1==t2&&prime[tt])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}