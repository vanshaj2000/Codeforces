#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int32_t main()
{
    fast_cin();
    int n,m;
    cin>>n>>m;
    int arr[n][m],sz[n][m];
    vector<int> dp(n,1);
    for(int j=0;j<m;j++)
    {
        int x;
        cin>>x;
        sz[0][j]=1;
        arr[0][j]=x;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int y;
            cin>>y;
            if(y>=arr[i-1][j])
                sz[i][j]=1+sz[i-1][j];
            else
                sz[i][j]=1;
            //cout<<sz[i][j]<<" ";
            dp[i]=max(dp[i],sz[i][j]);
            arr[i][j]=y;
        }
        cout<<endl;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        if(dp[r-1]>=(r-l+1))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}