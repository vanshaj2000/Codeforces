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
    int n,ans=1;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    if(n==1)
    {
        cout<<"1";
        return 0;
    }
    vector<int> left(n,1),right(n+2,1);
    for(int i=1;i<n;i++)
    {
        if(v[i]>v[i-1])
            left[i]=left[i-1]+1;
        else
            left[i]=1;
        if(v[n-i-1]<v[n-i])
            right[n-i-1]=right[n-i]+1;
        else
            right[n-i-1]=1;
    }
    //cout<<left[2]<<" "<<right[4]<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            ans=max(ans,1+right[i+1]);
        else if(i==n-1)
            ans=max(ans,1+left[i-1]);
        else
        {
            if(v[i+1]-v[i-1]>=2)
                ans=max(ans,left[i-1]+right[i+1]+1);
            else
                ans=max(ans,max(1+left[i-1],1+right[i+1]));
        }
    }
    cout<<ans;
}