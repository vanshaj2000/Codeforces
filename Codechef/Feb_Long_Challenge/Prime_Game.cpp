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
 

const int MAX = 1000000;  
ll prefix[MAX+1];
bool prime[MAX+1]={'\0'};
void buildPrefix() 
{
    memset(prime, true, sizeof(prime));
    for (ll p=2;p*p<=MAX;p++)
    { 
        if (prime[p]==true)
        { 
            for (int i=p*2;i<=MAX;i+=p) 
                prime[i]=false; 
        } 
    }
    prefix[0]=0;
    prefix[1]=0; 
    for (int p=2;p<=MAX;p++)
    { 
        prefix[p]=prefix[p - 1]; 
        if (prime[p]) 
            prefix[p]++;
    }
}
int main()
{
    buildPrefix();
    fast_cin();
    ll t;
    scanf("%lld",&t);
    for(int it=1;it<=t;it++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        if(y>=prefix[x])
            printf("Chef\n");
        else
            printf("Divyam\n");
    }
    return 0;
}