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
    int n,k,num=1;
    cin>>n>>k;
    vector<int> v(n),sum(n+1);
    map<int,int> mp;
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans=v[0];
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
        sum[i+1]=sum[i]+v[i];
    int i=n-1,j=n-2;
    while(j>=0&&i>=1)
    {
        int temp=sum[i]-sum[j];
        //cout<<sum[i]<<" "<<sum[j]<<endl;
        if((temp+k)<((i-j)*v[i]))
            i--;
        else
        {
            if(i-j+1>=num)
            {
                num=i-j+1;
                ans=v[i];
            }
            j--;
        }
    }
    cout<<num<<" "<<ans;
}