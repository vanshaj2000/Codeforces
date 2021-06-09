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
    int ans=0,rem=-1,prev=-1;
    for(int i=0;i<str.size();i++)
    {
        if((str[i]-'0')%3==0)
            rem=-1,ans++,prev=-1;
        else if(rem==-1)
            rem=(str[i]-'0')%3;
        else if((rem+((str[i]-'0')%3))==3||prev!=-1)
            ans++,rem=-1,prev=-1;
        else
            prev=rem,rem=(rem+((str[i]-'0')%3))%3;
    }
    cout<<ans;
    return 0;
}