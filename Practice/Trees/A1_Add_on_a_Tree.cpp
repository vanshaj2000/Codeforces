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
    vector<int> ind(n,0);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        ind[a-1]++,ind[b-1]++;
    }
    for(int i=0;i<n;i++)
    {
        if(ind[i]==2)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}