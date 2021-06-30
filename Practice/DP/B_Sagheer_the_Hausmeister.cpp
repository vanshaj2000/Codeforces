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
//unordered_map<int,int> ump;
int memo(int dir,vector<vector<int>> &ad,int curr,int m,int lim)
{
    if(curr==lim)
        return 0;
    if(curr==lim-1)
    {
        //cout<<ad[curr][dir]<<endl;
        return ad[curr][dir];
    }
    int x1=1+ad[curr][dir]+memo(dir,ad,curr+1,m,lim);
    int x2=2+m+memo(1-dir,ad,curr+1,m,lim);
    //cout<<lim<<" "<<x1<<" "<<x2<<endl;
    return min(x1,x2);
}
int main()
{
    fast_cin();
    int n,m,last=0;
    cin>>n>>m;
    vector<string> adj(n);
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        adj[i]=temp.substr(1,m);
    }
    reverse(adj.begin(),adj.end());
    vector<vector<int>> ad(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        int fs=m,ls=-1;
        for(int j=0;j<m;j++)
        {
            if(adj[i][j]=='1')
            {
                ls=j;
                if(fs==m)
                    fs=j;
            }
        }
        ad[i]={2*(ls+1),2*(m-fs)};
    }
    for(int i=n-1;i>=0;i--)
    {
        int fl=0;
        for(int j=0;j<m;j++)
        {
            if(adj[i][j]=='1')
                fl++;
        }
        if(fl)
        {
            ad[i][0]/=2;
            ad[i][1]/=2;
            last=i+1;
            break;
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<ad[i][0]<<" "<<ad[i][1]<<endl;
    cout<<memo(0,ad,0,m,last);
    return 0;
}