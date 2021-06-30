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
        int n,x,ret=0,fl=0;
        cin>>n>>x;
        x--;
        vector<int> ind(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            ind[a-1]++,ind[b-1]++;
        }
        string ans[2]={"Ayush","Ashish"};
        int y=ind[x];
        if(y<=1)
            cout<<ans[ret]<<endl;
        else
        {
            if((n-y-1)%2==0)
            {
                if(y%2==0)
                    cout<<ans[1-ret]<<endl;
                else
                    cout<<ans[ret]<<endl;
            }
            else
            {
                if(y%2==0)
                    cout<<ans[ret]<<endl;
                else
                    cout<<ans[1-ret]<<endl;
            }
        }
    }
}