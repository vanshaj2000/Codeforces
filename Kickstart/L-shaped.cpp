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
    int tt=1;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int>> arr(r,vector<int>(c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cin>>arr[i][j];
        }
        vector<vector<pair<int,int>>> hor(r,vector<pair<int,int>>(c));
        vector<vector<pair<int,int>>> ver(r,vector<pair<int,int>>(c));
        for(int i=0;i<r;i++)
        {
            hor[i][0].first=arr[i][0];
            for(int j=1;j<c;j++)
                hor[i][j].first=hor[i][j-1].first*arr[i][j]+arr[i][j];
        }
        for(int i=0;i<r;i++)
        {
            hor[i][c-1].second=arr[i][c-1];
            for(int j=c-2;j>=0;j--)
                hor[i][j].second=hor[i][j+1].second*arr[i][j]+arr[i][j];
        }
        for(int i=0;i<c;i++)
        {
            ver[0][i].first=arr[0][i];
            for(int j=1;j<r;j++)
                ver[j][i].first=ver[j-1][i].first*arr[j][i]+arr[j][i];
        }
        for(int i=0;i<c;i++)
        {
            ver[r-1][i].second=arr[r-1][i];
            for(int j=r-2;j>=0;j--)
                ver[j][i].second=ver[j+1][i].second*arr[j][i]+arr[j][i];
        }
        /*for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<hor[i][j].first<<hor[i][j].second<<ver[i][j].first<<ver[i][j].second<<" ";
            cout<<endl;
        }*/
        int ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(hor[i][j].first>=2&&ver[i][j].first>=2)
                {
                    //cout<<"1"<<endl;
                    int h=max(hor[i][j].first,ver[i][j].first);
                    int v=min(hor[i][j].first,ver[i][j].first);
                    int c1=v;
                    while(c1*2>h)
                        c1--;
                    ans+=c1-1;
                    int c2=v/2;
                    ans+=c2-1;
                }
                if(hor[i][j].first>=2&&ver[i][j].second>=2)
                {
                    //cout<<"2"<<endl;
                    int h=max(hor[i][j].first,ver[i][j].second),v=min(hor[i][j].first,ver[i][j].second);
                    int c1=v;
                    while(c1*2>h)
                        c1--;
                    ans+=c1-1;
                    int c2=v/2;
                    ans+=c2-1;
                }
                if(hor[i][j].second>=2&&ver[i][j].second>=2)
                {
                    //cout<<"3"<<endl;
                    int h=max(hor[i][j].second,ver[i][j].second),v=min(hor[i][j].second,ver[i][j].second);
                    int c1=v;
                    while(c1*2>h)
                        c1--;
                    ans+=c1-1;
                    int c2=v/2;
                    ans+=c2-1;
                }
                if(hor[i][j].second>=2&&ver[i][j].first>=2)
                {
                    //cout<<"4"<<endl;
                    int h=max(hor[i][j].second,ver[i][j].first),v=min(hor[i][j].second,ver[i][j].first);
                    int c1=v;
                    while(c1*2>h)
                        c1--;
                    ans+=c1-1;
                    int c2=v/2;
                    ans+=c2-1;
                }
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
        tt++;
    }
    return 0;
}