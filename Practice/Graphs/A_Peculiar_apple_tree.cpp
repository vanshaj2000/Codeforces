#include <bits/stdc++.h>  
using namespace std;
int maxDfs(int ind,vector<vector<int>> &adj,int curr,vector<int> &mini)
{
    int ret=curr;
    mini[ind]=min(mini[ind],ret);
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        ret=max(ret,maxDfs(u,adj,curr+1,mini));
    }
    return ret;
}
int main()
{
    int n,ans=0;
    cin>>n;
    vector<int> side(n+1),num(n+1,1);
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int> mini(n+1,INT_MAX);
    int d=maxDfs(1,adj,0,mini);
    //cout<<d<<endl;
    vector<int> v(d+1,0);
    v[0]=1;
    for(int i=2;i<=n;i++)
        v[mini[i]]++;
    for(int i=0;i<=d;i++)
        ans+=(v[i]%2);
    cout<<ans;
    return 0;
}