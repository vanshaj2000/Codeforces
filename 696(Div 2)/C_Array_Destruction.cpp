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
void solve(){
}
//Incorrect Solution
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++)
    {
        int n;
        cin>>n;
        vector<int> v(2*n);
        vector<bool> vis(2*n,false);
        map<int,int> mp;
        priority_queue<int> hep;
        for(int i=0;i<2*n;i++)
        {
            cin>>v[i];
            mp[v[i]]++;
            hep.push(v[i]);
        }
        sort(v.begin(),v.end());
        vector<pair<int,int>> ans;
        int flag=0;
        int x=v[2*n-1];
        hep.pop();
        mp[x]--;
        for(int i=0;i<n-1;i++)
        {
            int y=hep.top();
            if(mp[x-y]>0)
            {
                ans.push_back({x-y,y});
                hep.pop();
                mp[x-y]--;
                mp[y]--;
                x=y;
            }
            else
            {
                if(flag==0)
                {
                    hep.pop();
                    i--;
                    flag=1;
                }
                else
                    break;
            }
        }
        if(ans.size()!=n-1)
            cout<<"NO"<<endl;
        else
        {
            int z=0;
            for (auto it =mp.begin();it!=mp.end();++it)
            {
                if(it->second==1)
                {
                    z=it->first;
                    break;
                }
            }
            ans.insert(ans.begin(),{v[2*n-1],z});
            cout<<"YES"<<endl;
            cout<<v[2*n-1]+z<<endl;
            for(int i=0;i<n;i++)
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        //cout<<x<<endl;
    }
    return 0;
}