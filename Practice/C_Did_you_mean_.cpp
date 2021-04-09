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
    string str;
    cin>>str;
    int s=0,e=0;
    int flag=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
        {
            cout<<str[i];
            s=e=i+1;
            flag=0;
        }
        else
        {
            if(s==e)
            {
                cout<<str[i];
                e++;
            }
            else
            {
                if(str[i]==str[i-1])
                {
                    if(!flag)
                    {
                        e++;
                        cout<<str[i];
                    }
                    else
                    {
                        flag=0;
                        cout<<" ";
                        s=e=i;
                        i--;
                    }
                }
                else
                {
                    if(e-s==1)
                    {
                        cout<<str[i];
                        e++;
                        flag=1;
                    }
                    else
                    {
                        flag=0;
                        cout<<" ";
                        s=e=i;
                        i--;
                    }
                }
            }
        }
    }
    return 0;
}