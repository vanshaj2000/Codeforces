#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int flag,sum;
void dfs(int ind,vector<vector<int>> &adj,vector<int> &s)
{
    int ch=0;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        ch++;
        dfs(u,adj,s);
    }
    if(s[ind]==-1&&ch!=0)
    {
        s[ind]=LLONG_MAX;
        for(int i=0;i<adj[ind].size();i++)
            s[ind]=min(s[adj[ind][i]],s[ind]);
    }
    for(int i=0;i<adj[ind].size();i++)
    {
        if(s[adj[ind][i]]!=-1&&s[ind]>(s[adj[ind][i]]))
        {
            //cout<<s[ind]<<" "<<ind<<endl;
            flag++;
            return;
        }
    }
}
int dfs(int ind,vector<vector<int>> &adj,vector<int> &s,int par)
{
    int ret=0;
    if(s[ind]!=-1)
        ret=s[ind]-s[par];
    for(int i=0;i<adj[ind].size();i++)
        ret+=dfs(adj[ind][i],adj,s,ind);
    return ret;
}
int32_t main()
{
    fast_cin();
    flag=0,sum=0;
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> s(n);
    for(int i=1;i<n;i++)
    {
        int x;
        cin>>x;
        adj[x-1].push_back(i);
    }
    for(int i=0;i<n;i++)
        cin>>s[i];
    dfs(0,adj,s);
    if(flag)
    {
        cout<<"-1";
        return 0;
    }
    s.push_back(0);
    cout<<dfs(0,adj,s,n);
}