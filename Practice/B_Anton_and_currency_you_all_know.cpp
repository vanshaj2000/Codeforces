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
    string str;
    cin>>str;
    int n=str.size();
    int v[n];
    for(int i=0;i<n;i++)
        v[i]=str[i]-'0';
    if(n<3)
    {
        if(n<2)
            cout<<"-1";
        else
        {
            if(v[0]%2==1)
                cout<<"-1";
            else
                cout<<v[1]<<v[0];
        }
    }
    else
    {
        int li=-1;
        for(int i=0;i<n-1;i++)
        {
            if(v[i]%2==0)
            {
                li=i;
                if(v[i]<v[n-1])
                    break;
            }
        }
        if(li==-1)
            cout<<li;
        else
        {
            swap(v[li],v[n-1]);
            for(int i=0;i<n;i++)
                cout<<v[i];
        }
    }
    
}