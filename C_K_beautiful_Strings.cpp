//This is incorrect
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

int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    ll t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(n%k!=0)
            cout<<"-1"<<endl;
        else
        {
            vector<int> vis(26,0);
            for(int i=0;i<n;i++)
                vis[s[i]-'a']++;
            int flag=0;
            for(int i=0;i<26;i++)
            {
                if(vis[i]%k!=0)
                    flag++;
            }
            if(!flag)
            {
                cout<<s<<endl;
                continue;
            }
            vector<int> copy=vis;
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='z')
                {
                    vis[25]--;
                    continue;
                }
                vis[s[i]-'a']--;
                vis[s[i]-'a'+1]++;
                int sum=0;
                for(int j=0;j<26;j++)
                    sum+=(k-((vis[j])%k))%k;
                if((n-i-1)>=sum&&(n-i-1-sum)%k==0)
                {
                    string cp=s.substr(0,i+1);
                    cp[i]=s[i]+1;
                    string temp="";
                    for(int j=0;j<26;j++)
                    {
                        int x=(k-((vis[j])%k))%k;
                        for(int y=0;y<x;y++)
                            temp.push_back('a'+j);
                    }
                    for(int j=temp.size()+1;j<n-i-1;j++)
                        temp.push_back('a');
                    sort(temp.begin(),temp.end());
                    cout<<cp<<temp<<endl;
                    break;
                }
                else
                    vis[s[i]-'a'+1]--;
            }
        }
    }
    return 0;
}