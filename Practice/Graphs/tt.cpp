#include <bits/stdc++.h>
using namespace std;
bool dfs(int ind,vector<vector<int>> &adj,int tar,vector<bool> &vis)
{
    vis[ind]=true;
    if(ind==tar)
        return true;
    bool ans=false;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[i])
            ans=ans|dfs(u,adj,tar,vis);
    }
    return ans;
}
int main()
{
    vector<pair<int,int>> eds;
    vector<vector<int>> adj;
    int m;
    cin>>m;
    for(int l=0;l<m;l++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1)
        {
            eds.push_back({y,z});
            adj.push_back({});
            for(int i=0;i<eds.size()-1;i++)
            {
                if((y>eds[i].first&&y<eds[i].second)||(z>eds[i].first&&z<eds[i].second))
                    adj[eds.size()-1].push_back(i);
                if((eds[i].first>y&&eds[i].first<z)||(y<eds[i].second&&eds[i].second<z))
                    adj[i].push_back(eds.size()-1);
            }
        }
        else
        {
            vector<bool> vis(eds.size(),false);
            if(dfs(y-1,adj,z-1,vis))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}