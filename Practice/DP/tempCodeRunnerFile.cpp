#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int32_t main()
{
    fast_cin();
    vector<vector<int>> grid={{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}};
    int n=grid.size();
    vector<vector<int>> dis(n,vector<int>(n,100000000));
    vector<vector<int>> vis(n,vector<int>(n,0));
    dis[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    while(!pq.empty())
    {
        int dist=pq.top().first,x=pq.top().second.first,y=pq.top().second.second;
        cout<<x<<" "<<y<<endl;
        pq.pop();
        if(vis[x][y])
            continue;
        vis[x][y]=1;
        vector<vector<int>> v={{x,y-1},{x,y+1},{x-1,y},{x+1,y}};
        cout<<v[0][0]<<" "<<v[0][1]<<endl;
        for(int i=0;i<4;i++)
        {
            int cx=v[i][0],cy=v[i][1];
            if(cx<0||cy<0||cx>=n||cy>=n)
                continue;
            cout<<cx<<" "<<cy<<endl;
            if((dis[cx][cy])>(grid[x][y]+dist))
            {
                dis[cx][cy]=grid[x][y]+dist;
                pq.push({dis[cx][cy],{cx,cy}});
            }
        }
    }
    cout<<(dis[n-1][n-1]+grid[n-1][n-1]);
}