#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void recur(int i,int j,int dir,int curr,vector<vector<int>> &vis)
{
    if(i<0||j<0||curr>2||j>=vis[0].size()||i>=vis.size())
        return;
    vis[i][j]=1;
    if(dir==0)
    {
        recur(i+1,j,dir,curr,vis);
        recur(i-1,j,dir,curr,vis);
        recur(i,j+1,1-dir,curr+1,vis);
        recur(i,j-1,1-dir,curr+1,vis);
    }
    else
    {
        recur(i,j+1,dir,curr,vis);
        recur(i,j-1,dir,curr,vis);
        recur(i+1,j,1-dir,curr+1,vis);
        recur(i-1,j,1-dir,curr+1,vis);
    }
}
int main()
{
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<string> adj(n);
    for(int i=0;i<n;i++)
        cin>>adj[i];
    pair<int,int> st,en;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(adj[i][j]=='S')
                st={i,j};
            else if(adj[i][j]=='T')
                en={i,j};
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    return 0;
}