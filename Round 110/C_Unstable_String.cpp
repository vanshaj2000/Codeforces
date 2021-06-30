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
    int t;
    cin>>t;
    while(t--)
    {

        string str,temp;
        cin>>str;
        temp=str;
        vector<int> ret;
        int curr=1,neg=0,ans=0,ser=0;
        for(int i=1;i<str.size();i++)
        {
            if(abs(temp[i]-temp[i-1])==1)
                curr++,ser=0;
            else if(temp[i-1]=='?')
                curr++,ser=0;
            else if(temp[i]=='?')
            {
                ser++;
                temp[i]='1'-(temp[i-1]-'0');
                curr++;
            }
            else
            {
                ret.push_back(curr);
                curr=ser+1;
                neg+=(ser*(ser+1))/2;
                ser=0;
            }
        }
        ret.push_back(curr);
        for(int i=0;i<ret.size();i++)
            ans+=((ret[i]*(ret[i]+1))/2);
        cout<<ans-neg<<endl;
    }
}