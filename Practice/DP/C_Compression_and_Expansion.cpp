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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        stack<pair<int,string>> s;
        s.push({1,"1"});
        cout<<"1"<<endl;
        for(int i=1;i<n;i++)
        {
            if(v[i]==1)
            {
                pair<int,string> temp=s.top();
                string str=(temp.second)+"."+to_string(v[i]);
                s.push({v[i],str});
                cout<<str<<endl;
            }
            else if(v[i]==s.top().first+1)
            {
                string tem=s.top().second,num=to_string(s.top().first);
                tem=((tem.substr(0,tem.size()-num.size()))+(to_string(v[i])));
                s.push({v[i],tem});
                cout<<tem<<endl;
            }
            else if(v[i]==s.top().first)
                s.pop(),s.pop(),i--;
            else
                s.pop(),i--;
        }
    }
    return 0;
}