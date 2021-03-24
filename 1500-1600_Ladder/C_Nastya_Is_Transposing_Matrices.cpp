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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> A(n,vector<int>(m));
    vector<vector<int>> B(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>A[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>B[i][j];
    }
    string ans="YES";
    for(int i=n-1;i>=0;i--)
    {
       vector<int> va;
       vector<int> vb;
       int k=i;
       for(int j=0;k>=0&&j<m;j++)
       {
           va.push_back(A[k][j]);
           vb.push_back(B[k][j]);
           k--;
       }
       sort(va.begin(),va.end());
       sort(vb.begin(),vb.end());
       if(va!=vb)
       {
           ans="NO";
           break;
       }
    }
    for(int j=1;j<m;j++)
    {
       vector<int> va;
       vector<int> vb;
       int k=j;
       for(int i=n-1;k<m&&i>=0;i--)
       {
           va.push_back(A[i][k]);
           vb.push_back(B[i][k]);
           k++;
       }
       sort(va.begin(),va.end());
       sort(vb.begin(),vb.end());
       if(va!=vb)
       {
           ans="NO";
           break;
       }
    }
    cout<<ans;
    return 0;
}