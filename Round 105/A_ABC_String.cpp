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
        string a;
        cin>>a;
        string ch(3,'0');
        char c=a[0];
        ch[c-'A']='(';
        int n=a.size();
        if(a[0]==a[n-1])
            cout<<"NO"<<endl;
        else
        {
            //cout<<"Hemlo";
            ch[a[n-1]-'A']=')';
            //cout<<ch[0]<<" "<<ch[1]<<" "<<ch[2]<<" ";
            int flag=0;
            char tt[2]={'(',')'};
            for(int j=0;j<2;j++)
            {
                string temp=a;
                for(int i=0;i<n;i++)
                {
                    if(ch[a[i]-'A']!='0')
                        temp[i]=ch[a[i]-'A'];
                    else
                        temp[i]=tt[j];
                }
                //cout<<temp<<" ";
                int check=0;
                stack<int> s;
                for(int i=0;i<n;i++)
                {
                    if(temp[i]=='(')
                        s.push(1);
                    else
                    {
                        if(s.empty())
                            check++;
                        else
                            s.pop();
                    }
                }
                //cout<<s.size()<<" ";
                if(s.empty()&&!check)
                    flag++;
            }
            if(flag>0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}