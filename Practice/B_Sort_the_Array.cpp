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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int> v1=v;
    vector<int> v2=v;
    int flag=0;
    int s=0;
    int e=-1;
    int curr=0;
    for(int i=0;i<n-1;i++)
    {
        if(!curr)
        {
            if(!flag)
            {
                if(v[i+1]>v[i])
                    s++;
                else
                {
                    flag=1;
                    e=i+1;
                }
            }
            else
            {
                if(v[i+1]<v[i])
                    e++;
                else
                {
                    v[i]=v[s];
                    curr++;
                    i--;
                }
            }
        }
        else
        {
            if(v[i]>v[i+1])
            {
                cout<<"no";
                return 0;
            }
        }
    }
    if(e==-1)
        cout<<"yes\n1 1";
    else
    {
        auto it1=v2.begin(),it2=v2.begin();
        for(int i=0;i<s;i++)
            it1++;
        for(int i=0;i<=e;i++)
            it2++;
        reverse(it1,it2);
        sort(v1.begin(),v1.end());
        if(v1==v2)
            cout<<"yes"<<endl<<s+1<<" "<<e+1;
        else
            cout<<"no";
    }
    return 0;
}