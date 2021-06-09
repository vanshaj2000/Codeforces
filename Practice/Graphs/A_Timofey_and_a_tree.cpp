#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
bool dfs(int c,int ind,vector<vector<int>> &adj,vector<int> &vis,vector<int> &v)
{
    //cout<<ind+1<<" "<<v[ind]<<endl;
    vis[ind]=true;
    bool ret=(v[ind]==c)?true:false;
    if(!ret)
        return false;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            ret=ret&&dfs(c,u,adj,vis,v);
    }
    return ret;
}
int main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> v(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int i=0;i<n;i++)
        cin>>v[i];
    pair<int,int> ed={-1,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(v[i]!=v[adj[i][j]])
                ed.first=i,ed.second=adj[i][j];
        }
    }
    //cout<<ed.first<<" "<<ed.second<<endl;
    if(ed.first==-1)
        cout<<"YES"<<endl<<"1";
    else
    {
        bool ans=true;
        vector<int> vis(n,0);
        vis[ed.first]=1;
        for(int i=0;i<adj[ed.first].size();i++)
            ans=ans&&dfs(v[adj[ed.first][i]],adj[ed.first][i],adj,vis,v);
        if(ans)
        {
            cout<<"YES"<<endl<<ed.first+1;
            return 0;
        }
        bool ans1=true;
        vector<int> vis1(n,0);
        vis1[ed.second]=1;
        for(int i=0;i<adj[ed.second].size();i++)
            ans1=ans1&&dfs(v[adj[ed.second][i]],adj[ed.second][i],adj,vis1,v);
        if(ans1)
            cout<<"YES"<<endl<<ed.second+1;
        else
            cout<<"NO";
    }
    return 0;
}