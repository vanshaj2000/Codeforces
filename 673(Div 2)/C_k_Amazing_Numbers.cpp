#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 1000000007;
double eps = 1e-12;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        set<int> s;
        map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            m[v[i]].push_back(i);
            s.insert(v[i]);
        }
        vector<int> par;
        for(auto it=s.begin();it!=s.end();it++)
            par.push_back(*it);
        vector<int> ans(n+1,-1);
        for(int i=0;i<par.size();i++)
        {
            vector<int> temp=m[par[i]];
            int k=min(temp[0]+1,n-temp[temp.size()-1]);
            for(int j=1;j<temp.size();j++)
                k=max(k,temp[j]-temp[j-1]+1);
            if(ans[k]==-1)
                ans[k]=par[i];
        }
        for(int i=1;i<n;i++)
        {
            if(ans[i+1]==-1&&ans[i]!=-1)
                ans[i+1]=ans[i];
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}