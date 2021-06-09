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
void check(string &ans,string &temp)
{
    if(temp.size()<ans.size())
        ans=temp;
}
int main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str,ans="aaaa";
        cin>>str;
        unordered_map<string,int> ump;
        for(int i=1;i<=3;i++)
        {
            for(int j=0;j<=n-i;j++)
                ump[str.substr(j,i)]=1;
        }
        for(int i=0;i<26;i++)
        {
            string temp(1,char('a'+i));
            if(!ump[temp])
            {
                ans=temp;
                break;
            }
        }
        if(ans!="aaaa")
        {
            cout<<ans<<endl;
            continue;
        }
        for(int i=0;i<26;i++)
        {
            string temp(1,char('a'+i));
            //cout<<temp<<endl;
            for(int j=0;j<26;j++)
            {
                string temp2=temp;
                temp2.push_back(char('a'+j));
                if(!ump[temp2])
                    check(ans,temp2);
                for(int k=0;k<26;k++)
                {
                    string temp3=temp2;
                    temp3.push_back(char('a'+k));
                    if(!ump[temp3])
                        check(ans,temp3);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}