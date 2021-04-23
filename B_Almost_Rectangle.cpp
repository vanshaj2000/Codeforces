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
        int n;
        cin>>n;
        vector<string> str(n);
        for(int i=0;i<n;i++)
            cin>>str[i];
        int x1,y1,x2,y2;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!flag&&str[i][j]=='*')
                {
                    x1=i;
                    y1=j;
                    flag=1;
                }
                else if(flag&&str[i][j]=='*')
                {
                    x2=i;
                    y2=j;
                    break;
                }
            }
        }
        if(x1==x2)
        {
            if(x1!=n-1)
                str[x1+1][y1]=str[x2+1][y2]='*';
            else
                str[x1-1][y1]=str[x2-1][y2]='*';
        }
        else if(y1==y2)
        {
            if(y1!=n-1)
                str[x1][y1+1]=str[x2][y2+1]='*';
            else
                str[x1][y1-1]=str[x2][y2-1]='*';
        }
        else
            str[x1][y2]=str[x2][y1]='*';
        for(int i=0;i<n;i++)
            cout<<str[i]<<endl;
    }
    return 0;
}