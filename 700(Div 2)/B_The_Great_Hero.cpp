#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll g;
bool comp(vector<ll> v1,vector<ll> v2)
{
    /*ll temp1=(v1[1]/g)+(v1[1]%g==0?0:1);
    ll temp2=(v2[1]/g)+(v2[1]%g==0?0:1);
    temp1=temp1*v1[0];
    temp2=temp2*v2[0];
    return temp1<temp2;*/
    return v1[0]<v2[0];
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++)
    {
        g=0;
        ll A,B;
        int n;
        cin>>A>>B>>n;
        g=A;
        vector<vector<ll>> mon(n,vector<ll>(2));
        for(int i=0;i<n;i++)
            cin>>mon[i][0];
        for(int i=0;i<n;i++)
            cin>>mon[i][1];
        /*for(int i=0;i<n;i++)
            cout<<mon[i][0]<<endl;*/
        if(n!=1)
        {
            sort(mon.begin(),mon.end(),comp);
            for(int i=0;i<n-1;i++)
            {
                int att=(mon[i][1]/A)+(mon[i][1]%A==0?0:1);
                //cout<<att<<endl;
                B=B-(att*mon[i][0]);
            }
            if(B>0)
            {
                ll tt=(mon[n-1][1]/A)+(mon[n-1][1]%A==0?0:1);
                //cout<<tt<<endl;
                tt--;
                if((B-(tt*mon[n-1][0]))>0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
        else
        {
            ll tt=(mon[n-1][1]/A)+(mon[n-1][1]%A==0?0:1);
            //cout<<tt<<endl;
            tt--;
            if((B-(tt*mon[n-1][0]))>0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}