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
        int h,m;
        cin>>h>>m;
        string str;
        cin>>str;
        int ch=stoi(str.substr(0,2));
        int cm=stoi(str.substr(3,2));
        char h1,h2;
        char m1,m2;
        vector<int> arr(10,1000);
        arr[0]=0;
        arr[1]=1;
        arr[2]=5;
        arr[5]=2;
        arr[8]=8;
        while(true)
        {
            int outM=arr[(ch/10)]+arr[ch%10]*10;
            int outH=arr[(cm/10)]+arr[cm%10]*10;
            if(outM<m&&outH<h)
            {
                if(ch<10)
                    cout<<"0";
                cout<<ch<<":";
                if(cm<10)
                    cout<<"0";
                cout<<cm<<endl;
                break;
            }
            else
            {
                cm++;
                ch=ch+(cm/m);
                cm=cm%m;
                ch=ch%h;
            }
        }
    }
    return 0;
}