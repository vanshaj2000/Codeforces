#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int main()
{
    fast_cin();
    vector<string> adj(2);
    cin>>adj[0]>>adj[1];
    int n=adj[0].size(),ans=0,prev=0;
    for(int i=0;i<n;i++)
    {
        int size=0;
        size+=(adj[0][i]=='0')?1:0;
        size+=(adj[1][i]=='0')?1:0;
        prev+=size;
        if(prev>=3)
            ans++,prev-=3;
        else
            prev=size;
    }
    cout<<ans;
    return 0;
}