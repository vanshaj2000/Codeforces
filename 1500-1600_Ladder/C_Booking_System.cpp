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
bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    else
        return a.first<b.first;
}
bool comp2(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first)
        return a.first<b.first;
    else
        return a.second<b.second;
}
int main()
{
    fast_cin();
    ll n;
    cin>>n;
    vector<pair<int,int>> orig(n);
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    orig=v;
    int k;
    cin>>k;
    vector<pair<int,int>> cap;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        cap.push_back({x,i});
    }
    sort(v.begin(),v.end(),comp);
    sort(cap.begin(),cap.end(),comp2);
    vector<int> amo(k);
    vector<int> pos(k);
    for(int i=0;i<k;i++)
    {
        amo[i]=cap[i].first;
        pos[i]=cap[i].second;
    }
    vector<pair<int,int>> ans;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        auto it1=lower_bound(amo.begin(),amo.end(),v[i].first);
        if(it1==amo.end())
            continue;
        sum=sum+v[i].second;
        auto it2=find(orig.begin(),orig.end(),v[i]);
        orig[it2-orig.begin()]={-1,-1};
        ans.push_back({it2-orig.begin(),pos[it1-amo.begin()]});
        amo.erase(it1);
        int jok=it1-amo.begin();
        pos.erase(pos.begin()+jok);
    }
    cout<<ans.size()<<" "<<sum<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    return 0;
}