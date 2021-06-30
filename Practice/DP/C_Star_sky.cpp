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
    int n,q,c,xn=-1,xm=-1,xs=0;
    cin>>n>>q>>c;
    vector<vector<int>> temp;
    for(int i=0;i<n;i++)
    {
        int x,y,s;
        cin>>x>>y>>s;
        xs=max(s,xs);
        temp.push_back({x,y,s});
    }
    vector<vector<vector<int>>> dp(xs+1,vector<vector<int>>(100+1,vector<int>(100+1,0)));
    //cout<<xn<<" "<<xm<<endl;
    for(int i=0;i<n;i++)
    {
        int x=temp[i][0],y=temp[i][1],s=temp[i][2];
        dp[s][x][y]++;
    }
    for(int i=0;i<=xs;i++)
    {
        for(int j=1;j<=100;j++)
        {
            for(int k=1;k<=100;k++)
                dp[i][j][k]+=(dp[i][j][k-1]+dp[i][j-1][k]-dp[i][j-1][k-1]);
        }
    }
    for(int i=0;i<q;i++)
    {
        //cout<<"Hello"<<endl;
        int t,x1,y1,x2,y2,ans=0;
        cin>>t>>x1>>y1>>x2>>y2;
        for(int j=0;j<=xs;j++)
            ans+=(dp[j][x2][y2]+dp[j][x1-1][y1-1]-dp[j][x2][y1-1]-dp[j][x1-1][y2])*((j+t)%(c+1));
        cout<<ans<<endl;
    }
    return 0;
}