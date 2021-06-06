#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
/* INCOMPLETE, DO IT*/
int main()
{
    fast_cin();
    int q;
    cin>>q;
    while(q--)
    {
        int n,k,curr=0;
        cin>>n>>k;
        string str;
        cin>>str;
        vector<vector<int>> dp;
        for(int i=0;i<n-1;i++)
        {
            if((str[i]=='B'&&str[i+1]=='G')||(str[i]=='G'&&str[i+1]=='R')||(str[i]=='R'&&str[i+1]=='B'))
                curr++;
            else if(curr!=0)
                dp.push_back({i-curr,curr});
        }
        if(curr!=0)
            dp.push_back({n-1-curr,curr});
        for(int i=0;i<dp.size();i++)
        {

        }
    }
    return 0;
}