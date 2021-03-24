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

int main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        cout<<t<<endl;
        int n;
        cin>>n;
        cout<<n;
        vector<vector<int>> v(n,vector<int>(n));
        vector<vector<int>> pr(10,vector<int>(4));
        vector<vector<pair<int,int>>> peer(10);
        for(int i=0;i<10;i++)
        {
            pr[i][0]=-1;
            pr[i][1]=n+1;
            pr[i][2]=-1;
            pr[i][3]=n+1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>v[i][j];
                cout<<v[i][j]<<" ";
                /*int in=v[i][j];
                peer[in].push_back({i,j});
                pr[in][0]=min(pr[in][0],i);
                pr[in][1]=max(pr[in][1],i);
                pr[in][2]=min(pr[in][2],j);
                pr[in][3]=max(pr[in][3],j);*/
            }
            cout<<endl;
        }
        /*for(int i=0;i<10;i++)
        {
            for(int j=0;j<peer[i].size();j++)
                cout<<peer[i][j].first<<" "<<peer[i][j].second;
            cout<<endl;
        }*/
        cout<<endl;
    }
    return 0;
}