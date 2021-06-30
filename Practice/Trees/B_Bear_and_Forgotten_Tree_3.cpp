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
    int n,d,h;
    cin>>n>>d>>h;
    int t=d/2+(d%2);
    if(h<t||n<(d+1)||n<(h+1)||(d==1&&n>2))
    {
        cout<<"-1";
        return 0;
    }
    for(int i=1;i<=(h);i++)
        cout<<i<<" "<<i+1<<endl;
    int s=d-h,curr=h+2,s2=2;
    if(s>0)
    {
        int prev=1;
        s2=1;
        for(int i=0;i<s;i++)
        {
            cout<<prev<<" "<<curr<<endl;
            prev=curr;
            curr++;
        }
    }
    int req=n-curr+1;
    for(int i=0;i<req;i++)
        cout<<s2<<" "<<curr<<endl,curr++;
}