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

int solve(int s,int e)
{
    cout<<"? "<<s<<" "<<e<<endl;
    cout.flush();
    int x;
    cin>>x;
    return x;
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int n;
    cin>>n;
    int s=1;
    int e=n;
    int t=40;
    while(t--)
    {
        if(e-s==1)
        {
            int x=solve(s,e);
            cout<<"! "<<s+e-x<<endl;
            cout.flush();
            break;
        }
        else if(e==s)
        {
            cout<<"! "<<s<<endl;
            cout.flush();
            break;
        }
        else
        {
            int prev=solve(s,e);
            int mid=(s+e)/2;
            if(prev<=mid)
            {
                int x=solve(s,mid);
                if(x==prev)
                    e=mid;
                else
                    s=mid+1;
            }
            else
            {
                int x=solve(mid,e);
                if(x==prev)
                    s=mid;
                else
                    e=mid-1;
            }
        }
    }
    return 0;
}