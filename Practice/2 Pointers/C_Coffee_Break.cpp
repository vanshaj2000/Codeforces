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
#define int long long int
int32_t main()
{
    fast_cin();
    int n,m,d;
    cin>>n>>m>>d;
    vector<int> a(n);
    unordered_map<int,int> day;
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> b=a;
    sort(a.begin(),a.end());
    int s=0,dd=1,dis=0;
    while(s!=n)
    {
        if(!day[a[s]])
        {
            day[a[s]]=dd;
            dd++;
        }
        int temp=a[s]+d+1;
        int it=lower_bound(a.begin()+dis+1,a.end(),temp)-a.begin();
        if(it!=n)
        {
            day[a[it]]=day[a[s]];
            dis=it;
        }
        s++;
    }
    cout<<dd-1<<endl;
    for(int i=0;i<n;i++)
        cout<<day[b[i]]<<" ";
    return 0;
}