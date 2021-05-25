#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int main()
{
    fast_cin();
    int n,k;
    cin>>n>>k;
    vector<vector<int>> adj(k);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
            adj[i].push_back(j);
    }
    stack<int> st;
    string ans;
    st.push(0);
    int curr=0;
    while(!st.empty())
    {
        if(adj[curr].size()>0)
        {
            int nt=adj[curr].back();
            st.push(nt);
            adj[curr].pop_back();
            curr=nt;
        }
        else
        {
            ans.push_back('a'+curr);
            curr=st.top();
            st.pop();
        }
    }
    ans=ans.substr(1,k*k);
    string res="";
    int x=n/(k*k);
    for(int i=0;i<x;i++)
        res+=ans;
    res+=ans.substr(0,n%(k*k));
    cout<<res;
    return 0;
}