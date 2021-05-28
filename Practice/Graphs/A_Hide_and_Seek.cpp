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
    int n,k;
    cin>>n>>k;
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    vector<int> fo(n+2,0),num(n+2,2);
    num[1]=1,num[n]=1;
    fo[0]=0,fo[n+1]=k+2;
    vector<vector<int>> flag(n+2,vector<int>(2,0));
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        if(!fo[x])
            fo[x]=i+1;
        if(fo[x-1]&&fo[x-1]<i+1&&!flag[x-1][0])
        {
            flag[x-1][0]=1;
            num[x-1]--;
        }
        if(fo[x+1]&&fo[x+1]<i+1&&!flag[x+1][1])
        {
            flag[x+1][1]=1;
            num[x+1]--;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!fo[i])
            ans++;
        ans+=num[i];
    }
    cout<<ans;
    return 0;
}