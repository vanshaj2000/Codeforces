#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int ans=0;
    string str;
    cin>>str;
    vector<int> vis(26,0),vis2(26,0);
    for(int i=0;i<str.size();i++)
    {
        vis[str[i]-'a']++;
        ans=max(ans,vis[str[i]-'a']);
    }
    vector<vector<int>> v(26,vector<int>(26,0));
    for(int i=0;i<str.size();i++)
    {
        for(int j=0;j<26;j++)
            v[j][str[i]-'a']+=vis2[j],ans=max(ans,v[j][str[i]-'a']);
        vis2[str[i]-'a']++;
    }
    cout<<ans;
    return 0;
}