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
        int flag=0;
        int a,b,n;
        cin>>a>>b;
        n=a+b;
        string str;
        cin>>str;
        if(n==1)
        {
            if(str[0]=='?')
            {
                if(a==1)
                    cout<<"0"<<endl;
                else
                    cout<<"1"<<endl;
            }
            else
            {
                if(a==1)
                {
                    if(str[0]=='0')
                        cout<<"0"<<endl;
                    else
                        cout<<"-1"<<endl;
                }
                else
                {
                    if(str[0]=='1')
                        cout<<"1"<<endl;
                    else
                        cout<<"-1"<<endl;
                }
            }
            continue;
        }
        for(int i=0;i<n/2;i++)
        {
            if(str[i]!=str[n-i-1])
            {
                if(str[i]=='?'||str[n-i-1]=='?')
                {
                    if(str[i]=='0'||str[n-i-1]=='0')
                    {
                        str[i]=str[n-i-1]='0';
                        a-=2;
                    }
                    else
                    {
                        str[i]=str[n-i-1]='1';
                        b-=2;
                    }
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            else
            {
                if(str[i]!='?')
                {
                    if(str[i]=='0')
                        a-=2;
                    else
                        b-=2;
                }
            }
        }
        for(int i=0;i<n/2;i++)
        {
            if(a<0||b<0)
            {
                flag++;
                break;
            }
            if(str[i]==str[n-i-1]&&str[i]=='?')
            {
                if(a<b)
                {
                    str[i]=str[n-i-1]='1';
                    b-=2;
                }
                else
                {
                    str[i]=str[n-i-1]='0';
                    a-=2;
                }
            }
        }
        if(n%2==1)
        {
            if(str[n/2]=='?')
            {
                if(a<b)
                {
                    str[n/2]='1';
                    b--;
                }
                else
                {
                    str[n/2]='0';
                    a--;
                }
            }
            else
            {
                if(str[n/2]=='1')
                    b--;
                else
                    a--;
            }
        }
        if(flag)
            cout<<"-1"<<endl;
        else
        {
            if(a==0&&b==0)
                cout<<str<<endl;
            else
                cout<<"-1"<<endl;
        }
    }
    return 0;
}