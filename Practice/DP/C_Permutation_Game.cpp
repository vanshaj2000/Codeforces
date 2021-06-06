#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int dfs(vector<vector<int>> &adj,int ind,vector<int> &los,vector<int> &vis)
{
    vis[ind]=1;
    if(adj[ind].size()==0)
        return los[ind]=0;
    int ret=0;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        ret=ret||(1-dfs(adj,u,los,vis));
    }
    return los[ind]=ret;
}
int main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<int> v(n),los(n,0),ans(n,0),vis(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    string win="BA";
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++)
    {
        int k=i-v[i],j=i+v[i],ch=0;
        while(j<n)
        {
            if(v[j]>v[i])
                adj[i].push_back(j),ch++;
            j+=v[i];
        }
        while(k>=0)
        {
            if(v[k]>v[i])
                adj[i].push_back(k),ch++;
            k-=v[i];
        }
        if(!ch)
            los[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            los[i]=dfs(adj,i,los,vis);
    }
    for(int i=0;i<n;i++)
        cout<<win[los[i]];
    return 0;
}