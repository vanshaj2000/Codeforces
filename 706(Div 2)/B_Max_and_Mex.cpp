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
        int n,k;
        cin>>n>>k;
        multiset<int> ms;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ms.insert(x);
        }
        set<int> s;
        for(auto it=ms.begin();it!=ms.end();it++)
            s.insert(*it);
        int b=*(--s.end());
        int a=0;
        for(auto it=s.begin();it!=s.end();it++)
        {
            if(*it==a)
                a++;
            else
                break;
        }
        if(a>b)
            cout<<s.size()+k<<endl;
        else
        {
            int c=(a+b)/2;
            if((a+b)%2!=0)
                c++;
            if(k>0)
                s.insert(c);
            cout<<s.size()<<endl;
        }   
    }
    return 0;
}