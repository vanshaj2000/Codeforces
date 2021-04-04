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
        string a,b;
        int n;
        cin>>n;
        cin>>a>>b;
        int flag=0;
        vector<pair<int,int>> pr(n,{0,0});
        if(a[0]=='0')
            pr[0].first=1;
        else
            pr[0].second=1;
        for(int i=1;i<n;i++)
        {
            pr[i]=pr[i-1];
            if(a[i]=='0')
                pr[i].first++;
            else
                pr[i].second++;
        }
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            char ch=a[i];
            if(flag)
            {
                if(ch=='0')
                    ch='1';
                else
                    ch='0';
            }
            if(ch!=b[i])
            {
                if(pr[i].first==pr[i].second)
                    flag=1-flag;
                else
                {
                    ans++;
                    break;
                }
            }
        }
        if(!ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}