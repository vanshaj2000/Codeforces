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
bool check(string x)
{
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='1')
            return true;
    }
    return false;
}
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
        int n,m;
        cin>>n>>m;
        vector<string> mat(n);
        for(int i=0;i<n;i++)
            cin>>mat[i];
        int flag=0;
        int mi=n-1;
        int mai=0;
        for(int i=0;i<n;i++)
        {
            if(check(mat[i]))
            {
                mi=min(mi,i);
                mai=max(mai,i);
            }
        }
        int s=m-1;
        int e=0;
        for(int i=0;i<m;i++)
        {
            if(mat[mi][i]=='1')
            {
                s=min(s,i);
                e=max(e,i);
            }
        }
        string str="";
        for(int i=0;i<(e-s+1);i++)
            str=str+"1";
        for(int j=mi;j<=mai;j++)
        {
            int s2=m-1;
            int e2=0;
            for(int i=0;i<m;i++)
            {
                if(mat[j][i]=='1')
                {
                    s2=min(s2,i);
                    e2=max(e2,i);
                }
            }
            if(s>e)
                flag++;
            else if(s2!=s||e2!=e||(mat[j].substr(s,e+1-s))!=str)
                flag++;
        }
        if(flag==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}