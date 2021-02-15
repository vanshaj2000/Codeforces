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
        ll n;
        cin>>n;
        if(n%2==1)
        {
            int sum=((n-1)/2)*3;
            vector<int> req(n,sum);
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(req[i]>0)
                    {
                        cout<<"1 ";
                        req[i]-=3;
                    }
                    else
                    {
                        cout<<"-1 ";
                        req[j]-=3;
                    }
                }
            }
        }
        else
        {
            int sum=((n-2)/2)*3;
            vector<int> req(n,sum);
            int flag=1;
            for(int i=0;i<n;i++)
            {
                if(i%2==0)
                    flag=0;
                else
                    flag=1;
                for(int j=i+1;j<n;j++)
                {
                    if(flag==0)
                    {
                        cout<<"0 ";
                        flag=-1;
                        continue;
                    }
                    if(req[i]>0)
                    {
                        cout<<"1 ";
                        req[i]-=3;
                    }
                    else
                    {
                        cout<<"-1 ";
                        req[j]-=3;
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}