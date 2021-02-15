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
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++)
    {
        int n;
        cin>>n;
        vector<string> v(n);
        unordered_map<string,int> ump;
        unordered_map<int,int> ump1;
        unordered_set<string> us;
        unordered_set<string> us1;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            us1.insert(v[i]);
            string temp=v[i].substr(1,v[i].size()-1);
            us.insert(temp);
            ump[temp]++;
            ump1[v[i][0]-'a']++;
        }
        vector<int> tch(26,0);
        vector<vector<int>> tin(26);
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<n;j++)
            {
                string temp=v[j];
                temp[0]='a'+i;
                if(us1.count(temp)==1)
                    tch[i]+=us1.count(temp);
                else
                    tin[i].push_back(v[j][0]-'a');
            }
        }
        vector<vector<int>> st(us.size());
        unordered_map<string,int> loc;
        unordered_map<int,string> loca;
        int j=0;
        for(auto itr=us.begin();itr!=us.end();itr++)
        {
            loc[*itr]=j;
            loca[j]=*itr;
            j++;
        }
        for(int i=0;i<n;i++)
        {
            string temp=v[i].substr(1,v[i].size()-1);
            int ind=loc[temp];
            //cout<<ind<<endl;
            st[ind].push_back(v[i][0]-'a');
        }
        ll ans=0;
        /*for(int i=0;i<st.size();i++)
        {
            for(int k=0;k<st[i].size();k++)
                cout<<ump1[st[i][k]]<<" ";
            cout<<endl;
        }*/
        for(int i=0;i<st.size();i++)
        {
            for(j=0;j<st[i].size();j++)
            {
                ll sum;
                sum=tch[st[i][j]];
                vector<int> tt(26,0);
                for(int k=0;k<tin[st[i][j]].size();k++)
                    tt[tin[st[i][j]][k]]++;
                for(int k=0;k<st[i].size();k++)
                    sum+=tt[st[i][k]];
                ans+=n-sum;
            }
        }
        //cout<<x<<endl;
        cout<<ans<<endl;
    }
    return 0;
}