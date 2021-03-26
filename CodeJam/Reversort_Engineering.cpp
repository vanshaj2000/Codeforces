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
        int n,c;
        cin>>n>>c;
        int up=((n*(n+1))/2)-1;
        int low=n-1;
        vector<int> ans(n,n);
        int curr=c;
        if(c>=low&&c<=up)
        {
            int ci=-1;
            int flag=0;
            for(int i=1;i<=n-1;i++)
            {
                int tem=curr-(n-i-1);
                if(tem>=n+1-i)
                {
                    curr-=n+1-i;
                    if(!flag)
                        ci=ci+n+1-i;
                    else
                        ci=ci-(n+1-i);
                    flag=1-flag;
                }
                else
                {
                    curr-=tem;
                    if(tem==1)
                    {
                        if(!flag)
                        {
                            for(int j=ci+1;j<n;j++)
                            {
                                if(ans[j]!=n)
                                    break;
                                else
                                {
                                    ans[j]=i;
                                    i++;
                                }
                            }
                            for(int j=ci-1;j>=0;j--)
                            {
                                if(ans[j]!=n)
                                    break;
                                else
                                {
                                    ans[j]=i;
                                    i++;
                                }
                            }
                        }
                        else
                        {
                            for(int j=ci-1;j>=0;j--)
                            {
                                if(ans[j]!=n)
                                    break;
                                else
                                {
                                    ans[j]=i;
                                    i++;
                                }
                            }
                            for(int j=ci+1;j<n;j++)
                            {
                                if(ans[j]!=n)
                                    break;
                                else
                                {
                                    ans[j]=i;
                                    i++;
                                }
                            }
                        }
                        break;
                    }
                    else
                    {
                        if(!flag)
                            ci=ci+tem;
                        else
                            ci=ci-tem;
                        flag=1-flag;
                    }
                }
                ans[ci]=i;
            }
            cout<<"Case #"<<tt<<": ";
            for(int i=0;i<n;i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
        else
            cout<<"Case #"<<tt<<": IMPOSSIBLE"<<endl;
    }
    return 0;
}