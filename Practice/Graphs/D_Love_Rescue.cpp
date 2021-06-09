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

int dfs(int ind,vector<vector<int>> &adj,vector<int> &vis,vector<int> &temp)
{
    vis[ind]=1;
    int ret=1;
    for(int i=0;i<adj[ind].size();i++)
    {
        int u=adj[ind][i];
        if(!vis[u])
            ret+=dfs(u,adj,vis,temp);
    }
    temp.push_back(ind);
    return ret;
}

int main()
{
    fast_cin();
    int n,ans=0;
    cin>>n;
    string str1,str2;
    cin>>str1>>str2;
    vector<vector<int>> ed(26,vector<int>(26,0)),adj(26);
    for(int i=0;i<26;i++)
        ed[i][i]=1;
    for(int i=0;i<n;i++)
    {
        if(!ed[str1[i]-'a'][str2[i]-'a'])
            adj[str1[i]-'a'].push_back(str2[i]-'a'),adj[str2[i]-'a'].push_back(str1[i]-'a');
        ed[str1[i]-'a'][str2[i]-'a']=ed[str2[i]-'a'][str1[i]-'a']=1;
    }
    //cout<<"Heloo"<<endl;
    vector<int> vis(26,0);
    vector<vector<int>> vec;
    for(int i=0;i<26;i++)
    {
        if(!vis[i])
        {
            vector<int> temp;
            ans+=dfs(i,adj,vis,temp)-1;
            int r=temp[0];
            //cout<<r<<endl;
            for(int j=1;j<temp.size();j++)
                vec.push_back({temp[j],r});
        }
    }
    cout<<ans<<endl;
    for(int j=0;j<vec.size();j++)
        cout<<char('a'+vec[j][0])<<" "<<char('a'+vec[j][1])<<endl;
    return 0;
}