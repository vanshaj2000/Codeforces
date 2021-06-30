#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int rem,tot,num,xx;
bool dfs(int ind,int tar,vector<vector<int>> &adj,vector<int> &vis)
{
    //cout<<ind+1<<endl;
    vis[ind]=1,tot++,num++;
    if(ind==tar)
        return true;
    bool ans=false;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
        {
            bool prev=ans;
            if(ind==xx)
                num=0;
            ans=(dfs(u,tar,adj,vis))||ans;
            if(ind==xx)
            {
                if(prev==false&&ans==true)
                    rem+=0;
                else
                    rem+=num;
                num=0;
            }
        }
    }
    return ans;
}
int32_t main()
{
    num=0,tot=0,rem=0;
    fast_cin();
    int n,x,y;
    cin>>n>>x>>y;
    x--,y--;
    xx=x;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> vis(n,0);
    bool ans=dfs(x,y,adj,vis);
    rem++;
    int ret=n-tot+1;
    //cout<<rem<<" "<<ret<<endl;
    cout<<((n*(n-1))-(ret*rem));
}