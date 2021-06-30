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
        int n=4;
        vector<int> v(n);
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            cin>>v[i],pq.push(v[i]);
        int x1=pq.top();
        pq.pop();
        int x2=pq.top();
        if(((v[0]==x1&&v[1]==x2)||(v[1]==x1&&v[0]==x2))||((v[2]==x2&&v[3]==x1)||(v[2]==x1&&v[3]==x2)))
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}