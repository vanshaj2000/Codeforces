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
    int n,k,sum=0,ind=-2;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    queue<int> q;
    vector<int> vec(n+1,0),ans(n+1,0);
    for(int i=0;i<n;i++)
    {
        if(q.size()<k)
        {
            ans[i+1]=i+1;
            if(sum<ans[i+1])
                sum=ans[i+1],ind=i;
            if(!v[i])
                q.push(i);
            continue;
        }
        if(!v[i])
        {
            q.push(i);
            int x=q.front();
            q.pop();
            ans[i+1]=i-x;
        }
        else
            ans[i+1]=ans[i]+1;
        if(sum<ans[i+1])
            sum=ans[i+1],ind=i;
    }
    int s=ind-sum+1;
    cout<<sum<<endl;
    for(int i=0;i<n;i++)
    {
        if(i>=s&&i<=ind)
            cout<<"1 ";
        else
            cout<<v[i]<<" ";
    }
}