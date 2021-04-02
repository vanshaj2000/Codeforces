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
    string str;
    cin>>str;
    int c=0;
    int flag=0;
    for(int i=0;i<str.size()-1;i++)
    {
        if(!flag)
        {
            if(str[i]=='A'&&str[i+1]=='B')
            {
                flag++;
                i++;
            }
        }
        else
        {
            if(str[i]=='B'&&str[i+1]=='A')
                c++;
        }
    }
    flag=0;
    for(int i=0;i<str.size()-1;i++)
    {
        if(!flag)
        {
            if(str[i]=='B'&&str[i+1]=='A')
            {
                flag++;
                i++;
            }
        }
        else
        {
            if(str[i]=='A'&&str[i+1]=='B')
                c++;
        }
    }
    if(c)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}