#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void dfs(int ind,string &ans,vector<vector<int>> &adj,vector<int> &vis)
{
    vis[ind]=1;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            dfs(u,ans,adj,vis);
    }
    ans.push_back('a'+ind);
}
int main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int fl=0;
        string str,ans="";
        cin>>str;
        vector<vector<int>> vis(26,vector<int>(26,0)),adj(26);
        vector<int> vis2(26,0);
        for(int i=0;i<str.size()-1;i++)
        {
            if(!vis[str[i]-'a'][str[i+1]-'a'])
            {
                vis[str[i]-'a'][str[i+1]-'a']=1;
                vis[str[i+1]-'a'][str[i]-'a']=1;
                adj[str[i]-'a'].push_back(str[i+1]-'a');
                adj[str[i+1]-'a'].push_back(str[i]-'a');
            }
            if((adj[str[i+1]-'a'].size()>=3)||adj[str[i]-'a'].size()>=3)
                fl++;
        }
        if(fl)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<26;i++)
        {
            string temp="";
            if(!vis2[i]&&adj[i].size()==1)
                dfs(i,temp,adj,vis2);
            ans+=temp;
        }
        for(int i=0;i<26;i++)
        {
            if(!vis2[i]&&adj[i].size()==2)
                fl++;
        }
        for(int i=0;i<26;i++)
        {
            if(!vis2[i])
                ans.push_back('a'+i);
        }
        if(!fl)
            cout<<"YES"<<endl<<ans<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}