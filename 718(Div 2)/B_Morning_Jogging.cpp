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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vec(n,vector<int>(m,-1));
        vector<vector<int>> glob,ans(n,vector<int>(m,-1));
        unordered_map<int,pair<int,int>> ump;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                vec[i][j]=x;
                glob.push_back({x,i,j});
            }
        }
        sort(glob.begin(),glob.end());
        for(int i=0;i<m;i++)
            ump[i]={glob[i][1],glob[i][2]};
        for(int i=0;i<n;i++)
        {
            stack<int> st;
            unordered_set<int> ms;
            for(int j=0;j<m;j++)
                ms.insert(j);
            for(int j=0;j<m;j++)
            {
                if(ump[j].first==i)
                    ms.erase(ump[j].second),ans[i][j]=vec[i][ump[j].second];
            }
            for(auto it=ms.begin();it!=ms.end();it++)
                st.push(*it);
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]==-1)
                    ans[i][j]=vec[i][st.top()],st.pop();
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
}