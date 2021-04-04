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
        int n;
        cin>>n;
        string str;
        cin>>str;
        vector<int> dp(n+1);
        int req1=0,req2=0;
        int c1=0,c2=0;
        string ans=str;
        int flag=0;
        for(int i=n-1;i>=0;i--)
        {
            if(req1>0||req2>0)
                break;
            if(str[i]=='0')
            {
                if(req1==0&&req2==0)
                {
                    req1++;
                    break;
                }
                else if(req1<0&&req2<0)
                {
                    if(req1>req2)
                    {
                        req2++;
                        req1--;
                        ans[i]=')';
                    }
                    else
                    {
                        req2--;
                        req1++;
                        ans[i]='(';
                    }
                }
                else if(req1==0)
                {
                    req1--;
                    req2++;
                    ans[i]=')';
                }
                else
                {
                    req1++;
                    req2--;
                    ans[i]='(';
                }
            }
            else
            {
                if(req1==0&&req2==0)
                {
                    req1=req2=-1;
                    ans[i]=')';
                }
                else if(req1<0&&req2<0)
                {
                    req1++;
                    req2++;
                    ans[i]='(';
                }
                else
                {
                    req1--;
                    req2--;
                    ans[i]=')';
                }
            }
        }
        if(req1==0&&req2==0)
        {
            cout<<"YES"<<endl;
            string b=ans;
            for(int i=0;i<n;i++)
            {
                if(str[i]=='0')
                {
                    if(b[i]==')')
                        b[i]='(';
                    else
                        b[i]=')';
                }
            }
            cout<<b<<endl<<ans<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}