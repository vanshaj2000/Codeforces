#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int getNext(int j,string &str)
{
    j++;
    while(str[j]=='1')
        j++;
    return j;
}
int32_t main()
{
    fast_cin();
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    vector<int> dp(n+1,0);
    int s=0,e=0,ans=LLONG_MAX,num=0;
    int l=getNext(-1,str);
    int r=l,m=l;
    for(int i=0;i<k;i++)
        r=getNext(r,str);
    while(r<n)
    {
        while(max(m-l,r-m)>max(getNext(m,str)-l,r-getNext(m,str)))
            m=getNext(m,str);
        ans=min(ans,max(m-l,r-m));
        l=getNext(l,str);
        r=getNext(r,str);
    }
    cout<<ans;
}