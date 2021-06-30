#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
void flps(string &str,vector<int> &lps)
{
    int i=1,j=0;
    lps[0]=0;
    while(i<lps.size())
    {
        if(str[j]==str[i])
        {
            lps[i]=j+1;
            i++,j++;
        }
        else
        {
            if(j==0)
                lps[i]=0,i++;
            else
                j=lps[j-1];
        }
    }
}
int32_t main()
{
    fast_cin();
    string str;
    cin>>str;
    
}