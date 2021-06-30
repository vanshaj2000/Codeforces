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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<vector<int>> vec(n,vector<int>(n,-1));
    int curr=v[n-1];
    for(int i=n-1;i>=0&&curr>0;i--)
        vec[n-1][i]=v[n-1],curr--;
    for(int i=n-2;i>=0;i--)
    {
        int c=v[i];
        vec[i][i]=v[i];
        c--;
        int k=i+1;
        while(k<n&&vec[k][i]==-1)
            k++;
        k--;
        for(int jj=k;jj>i&&c>0;jj--)
            vec[jj][i]=v[i],c--;
        for(int j=i-1;j>=0&&c>0;j--)
        {
            int k=i+1;
            while(k<n&&vec[k][j]==-1)
                k++;
            k--;
            for(int jj=k;jj>=i&&c>0;jj--)
                vec[jj][j]=v[i],c--;
        }
    }
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            if(vec[i][j]==-1)
            {
                cout<<"-1";
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
}