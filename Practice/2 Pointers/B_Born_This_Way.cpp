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
    int n,m,ta,tb,k,fl=0;
    cin>>n>>m>>ta>>tb>>k;
    vector<int> va(n),vb(m);
    for(int i=0;i<n;i++)
        cin>>va[i];
    for(int i=0;i<m;i++)
        cin>>vb[i];
    int pa=0,pb=0;
    if(k>=n||k>=m)
    {
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<=k;i++)
    {
        int x=va[i]+ta;
        int it=lower_bound(vb.begin(),vb.end(),x)-vb.begin();
        int temp=it+k-i;
        fl=max(fl,temp);
        if(fl>=m)
        {
            //cout<<i<<endl;
            fl=m;
            break;
        }
    }
    vb.push_back(-1-tb);
    cout<<vb[fl]+tb;
}