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
        ll n;
        cin>>n;
        string str;
        cin>>str;
        int rf=0,al=0,bob=0,freq=0,pf=0;
        for(int i=0;i<n;i++)
            freq+=str[i]-'0';
        freq=n-freq;
        if(freq==1)
            cout<<"BOB"<<endl;
        else
        {
            if(freq%2==1)
                cout<<"ALICE"<<endl;
            else
                cout<<"BOB"<<endl;
        }
    }
    return 0;
}