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
    int n,ans=0;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i+=2)
    {
        if((str[i]=='a'&&str[i+1]=='a')||(str[i]=='b'&&str[i+1]=='b'))
        {
            str[i]='a'+1-(str[i]-'a');
            ans++;
        }
    }
    cout<<ans<<endl<<str;
    return 0;
}