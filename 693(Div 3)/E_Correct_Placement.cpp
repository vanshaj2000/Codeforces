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

bool cus(pair<int,int> p1,pair<int,int> p2)
{
    int min1=min(p1.first,p1.second);
    int max1=max(p1.first,p1.second);
    int min2=min(p2.first,p2.second);
    int max2=max(p2.first,p2.second);
    if(min1==min2)
        return max1<max2;
    else
        return min1<min2;
}
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
        vector<pair<int,int>> pr(n);
        vector<pair<int,int>> pr1(n);
        map<pair<int,int>,int> mp1;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            pr[i].first=min(x,y);
            pr[i].second=max(x,y);
            mp1[pr[i]]=i;
        }
        pr1=pr;
        sort(pr1.begin(),pr1.end(),cus);
        int mini=0;
        int prev=0;
        vector<int> ind(n);
        //pr1.push_back(pr1[n-1]);
        for(int i=1;i<n;i++)
        {
            //ind[i]=prev;
            if(min(pr1[i].first,pr1[i].second)!=min(pr1[i-1].first,pr1[i-1].second))
            {
                ind[i]=mini;
                prev=mini;
            }
            else
                ind[i]=prev;
            if(max(pr1[mini].first,pr1[mini].second)>max(pr1[i].first,pr1[i].second))
                mini=i;
        }
        map<pair<int,int>,int> mp2;
        mp2[pr1[0]]=-2;
        for(int i=1;i<n;i++)
        {
            mp2[pr1[i]]=-2;
            int j=ind[i];
            int min1=min(pr1[i].first,pr1[i].second);
            int max1=max(pr1[i].first,pr1[i].second);
            int min2=min(pr1[j].first,pr1[j].second);
            int max2=max(pr1[j].first,pr1[j].second);
            if(min1>min2&&max1>max2)
                mp2[pr1[i]]=mp1[pr1[j]];
        }
        for(int i=0;i<n;i++)
            cout<<mp2[pr[i]]+1<<" ";
        cout<<endl;
    }
    return 0;
}