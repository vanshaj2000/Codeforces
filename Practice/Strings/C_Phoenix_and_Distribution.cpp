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
        int n,k,curr;
        cin>>n>>k;
        curr=k-1;
        string str,ans="";
        cin>>str;
        sort(str.begin(),str.end());
        while(curr<n)
        {
            ans.push_back(str[curr]);
            if(curr==n-1)
                break;
            int num=curr,c=0;
            char ch=str[num];
            while(num>=0&&c<k&&str[num]==ch)
                c++,num--;
            if(c==k)
                curr+=k;
            else
                break;
            if(curr>=n)
                ans.push_back(str[n-1]);
        }
        ans=min(ans,str.substr(k-1,n-k+1));
        cout<<ans<<endl;
    }
}