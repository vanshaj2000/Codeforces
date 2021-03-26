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
        int n,t,r,b,l;
        cin>>n>>t>>r>>b>>l;
        int flag=0;
        for(int i=0;i<=15;i++)
        {
            int j=i;
            int tn=t,rn=r,ln=l,bn=b;
            int c4=j%2;
            j=j>>1;
            int c3=j%2;
            j=j>>1;
            int c2=j%2;
            j=j>>1;
            int c1=j%2;
            if(c1==1)
            {
                tn--;
                ln--;
            }
            if(c2==1)
            {
                tn--;
                rn--;
            }
            if(c3==1)
            {
                bn--;
                rn--;
            }
            if(c4==1)
            {
                bn--;
                ln--;
            }
            if(tn>=0&&tn<=n-2&&rn>=0&&rn<=n-2&&bn>=0&&bn<=n-2&&ln>=0&&ln<=n-2)
                flag++;
        }
        if(!flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}