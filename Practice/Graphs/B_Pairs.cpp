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
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    vector<int> arr={a,b};
    string ans="NO";
    int ch1=0,ch2=0,maxi1=0,maxi2=0;
    vector<int> check1(n+1,0),check2(n+1,0);
    for(int i=0;i<m-1;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x!=arr[0]&&y!=arr[0])
        {
            check1[x]++,check1[y]++,ch1++;
            maxi1=max(maxi1,max(check1[x],check1[y]));
        }
        if(x!=arr[1]&&y!=arr[1])
        {
            check2[x]++,check2[y]++,ch2++;
            maxi2=max(maxi2,max(check2[x],check2[y]));
        }
    }
    if(ch1==maxi1||ch2==maxi2)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}