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
    int m;
    cin>>m;
    vector<int> vb(m);
    for(int i=0;i<m;i++)
        cin>>vb[i];
    v.push_back(0),vb.push_back(0);
    int l=0,j=0,k=0,asum=v[0],bsum=vb[0];
    while(j<n&&k<m)
    {
        if(asum==bsum)
        {
            j++,k++,l++;
            asum=v[j],bsum=vb[k];
        }
        else if(asum>bsum)
            k++,bsum+=vb[k];
        else
            j++,asum+=v[j];
    }
    if(j==n&&k==m)
        cout<<l;
    else
        cout<<"-1";
}