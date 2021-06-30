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
    int n,k,l,r,ans=0;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    //cout<<n<<k<<endl;
    vector<int> ump(1000001,0);
    //cout<<"Hello"<<endl;
    int pt1=0,pt2=0,curr=0;
    while(pt2<n)
    {
        //cout<<"hell"<<endl;
        if(curr>k)
        {
            ump[v[pt1]]--;
            if(ump[v[pt1]]==0)
                curr--;
            pt1++;
        }
        else
        {
            ump[v[pt2]]++;
            if(ump[v[pt2]]==1)
                curr++;
            if(curr<=k&&ans<(pt2-pt1+1))
                ans=pt2-pt1+1,l=pt1,r=pt2;
            pt2++;
        }
    }
    cout<<l+1<<" "<<r+1;
}