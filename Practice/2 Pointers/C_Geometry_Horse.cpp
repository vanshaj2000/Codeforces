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
    vector<vector<int>> vec(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>vec[i][1]>>vec[i][0];
    sort(vec.begin(),vec.end());
    int t;
    cin>>t;
    vector<int> p(t);
    for(int i=0;i<t;i++)
        cin>>p[i];
    int f=1,i=0,j=-1,num=0,ans=0;
    while(i<n)
    {
        //cout<<num<<" "<<ans<<endl;
        if(j==t-1)
        {
            ans+=(vec[i][0]*vec[i][1]*f);
            i++;
            continue;
        }
        if(num+vec[i][1]>=p[j+1])
        {
            ans+=(vec[i][0]*(p[j+1]-num)*f);
            vec[i][1]-=(p[j+1]-num);
            num=p[j+1];
            j++;
            f++;
        }
        else
        {
            ans+=(vec[i][0]*vec[i][1]*f);
            num+=vec[i][1];
            i++;
        }
    }
    cout<<ans;
}