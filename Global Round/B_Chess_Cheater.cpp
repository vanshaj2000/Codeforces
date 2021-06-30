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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,c=0,rem=0,tot=0;
        cin>>n>>k;
        string str;
        cin>>str;
        map<int,int> ump;
        int curr=0,fl=0,prof=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='W')
            {
                if(i==0||str[i-1]=='L')
                    tot++;
                else
                    tot+=2;
            }
            if(str[i]=='W'&&curr==0)
                fl=1;
            else if(str[i]=='W'&&curr!=0&&!fl)
                curr=0,fl=1;
            else if(str[i]=='W'&&curr!=0&&fl)
                ump[curr]++,curr=0;
            else
                curr++,c++;
        }
        if(c==n)
        {
            if(k==0)
            {
                cout<<"0"<<endl;
                continue;
            }
            int p=1;
            p+=(2*(k-1));
            cout<<p<<endl;
            continue;
        }
        auto it=(ump.begin());
        for(int i=0;i<ump.size();i++)
        {
            int val=it->first,num=it->second;
            if(k<val)
                break;
            int x=min(k/val,num);
            prof+=(2*val+1)*x;
            k-=(x*val);
            c-=(x*val);
            it++;
        }
        prof+=(min(c,k)*2);
        cout<<tot+prof<<endl;
    }
}