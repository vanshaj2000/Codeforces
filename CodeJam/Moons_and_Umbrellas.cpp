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
    int tt=0;
    while(t--)
    {
        tt++;
        int x,y;
        string str;
        cin>>x>>y>>str;
        int n=str.size();
        int ans=0;
        string s="";
        for(int i=0;i<n;i++)
        {
            if(str[i]!='?')
            {
                s=str.substr(i,n-i);
                break;
            }
        }
        n=s.size();
        //cout<<n<<" ";
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='?')
            {
                if(s[i-1]!='?'&&s[i+1]!='?')
                {
                    if(s[i-1]!=s[i+1])
                    {
                        if(s[i-1]=='C')
                            ans+=x;
                        else
                            ans+=y;
                    }
                }
                else if(s[i-1]!='?'&&s[i+1]=='?')
                    s[i]=s[i-1];
            }
            else
            {
                if(s[i-1]=='C'&&s[i]=='J')
                    ans+=x;
                else if(s[i-1]=='J'&&s[i]=='C')
                    ans+=y;
            }
        }
        if(s[n-1]!='?')
        {
            if(s[n-2]=='C'&&s[n-1]=='J')
                    ans+=x;
            else if(s[n-2]=='J'&&s[n-1]=='C')
                    ans+=y;
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}