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
    int k,ans=0,curr=0;
    cin>>k;
    string str;
    cin>>str;
    unordered_map<int,int> ump;
    ump[0]=1;
    for(int i=0;i<str.size();i++)
    {
        curr+=(str[i]-'0');
        ans+=ump[curr-k];
        ump[curr]++;
    }
    cout<<ans<<endl;
}
