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
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    int sum[m][n];
    for(int i=0;i<m;i++)
    {
        sum[i][0]=arr[0][i];
        for(int j=1;j<n;j++)
            sum[i][j]=(sum[i][j-1]+arr[j][i]);
    }
    int ans=0,curr=0;
    for(int i=0;i<m;i++)
    {
        int lans=0,lc=0,llc=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j][i]==1)
            {
                int indi=min(j+k-1,n-1);
                int req=sum[i][indi]-(j==0?0:sum[i][j-1]);
                //cout<<req<<" ";
                if(req>lans)
                    lans=req,lc=llc;
                llc++;
            }
        }
        //cout<<endl;
        //cout<<lans<<" "<<lc<<endl;
        ans+=lans,curr+=lc;
    }
    cout<<ans<<" "<<curr;
}