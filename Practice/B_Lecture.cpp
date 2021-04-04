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
    int n,m;
    cin>>n>>m;
    unordered_map<string,string> l1;
    unordered_map<string,string> l2;
    for(int i=0;i<m;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        l1[s1]=s1;
        l1[s2]=s1;
        l2[s1]=s2;
        l2[s2]=s2;
    }
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        string str1=l1[str];
        string str2=l2[str];
        if(str2.size()<str1.size())
            cout<<str2<<" ";
        else
            cout<<str1<<" ";
    }
    return 0;
}