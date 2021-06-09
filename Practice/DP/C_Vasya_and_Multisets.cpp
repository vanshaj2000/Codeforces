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
    int n;
    cin>>n;
    string ans="AB";
    vector<int> v(n),ons,tns;
    unordered_map<int,int> ump,umpA;
    for(int i=0;i<n;i++)
        cin>>v[i],ump[v[i]]++;
    for(int i=0;i<n;i++)
    {
        if(ump[v[i]]>=3)
            tns.push_back(v[i]);
        else if(ump[v[i]]==1)
            ons.push_back(v[i]);
    }
    if(ons.size()%2!=0&&tns.size()==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    if(ons.size()%2!=0)
        ons.push_back(tns[0]),umpA[tns[0]]=1;
    for(int i=0;i<ons.size();i++)
        umpA[ons[i]]+=i%2;
    for(int i=0;i<n;i++)
    {
        if(umpA[v[i]]==2)
            cout<<"B",umpA[v[i]]=0;
        else
            cout<<ans[umpA[v[i]]];
    }
    return 0;
}