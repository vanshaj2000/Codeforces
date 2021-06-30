#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str,ans;
        cin>>str;
        int n=str.size();
        vector<bool> vis(n,false);
        vector<pair<int,int>> odd,ev;
        for(int i=n-1;i>=0;i--)
        {
            if((str[i]-'0')%2)
                odd.push_back({str[i]-'0',i});
            else
                ev.push_back({str[i]-'0',i});
        }
        int i=0;
        while(i<n)
        {
            if(vis[i])
            {
                i++;
                continue;
            }
            if(str[i]=='0')
            {
                ans.push_back('0'),i++;
                ev.pop_back();
            }
            else
            {
                if((str[i]-'0')%2==1)
                {
                    if(ev.size()>0)
                    {
                        if(ev.back().first<odd.back().first)
                        {
                            ans.push_back('0'+ev.back().first);
                            vis[ev.back().second]=true;
                            ev.pop_back();
                        }
                        else
                            ans.push_back(str[i]),odd.pop_back(),i++;
                    }
                    else
                        ans.push_back(str[i]),odd.pop_back(),i++;
                }
                else
                {
                    //cout<<str[i]<<endl;
                    if(odd.size()>0)
                    {
                        if(odd.back().first<ev.back().first)
                        {
                            ans.push_back('0'+odd.back().first);
                            vis[odd.back().second]=true;
                            odd.pop_back();
                        }
                        else
                            ans.push_back(str[i]),ev.pop_back(),i++;
                    }
                    else
                        ans.push_back(str[i]),ev.pop_back(),i++;
                }
            }
        }
        cout<<ans<<endl;
    }
}