#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define maxin 200001
int primes[maxin];
void sieve()
{
    memset(primes,-1,sizeof(primes));
    for(int p=2;p*p<maxin;p++)
    {
        if(primes[p]==-1)
        {
            for(int i=p*p;i<maxin;i+=p)
            {
                if(primes[i]==-1)
                    primes[i]=p;
            }
        }
    }
}
int main()
{
    fast_cin();
    sieve();
    int n;
    cin>>n;
    vector<int> ans;
    map<int,int> comp,tot;
    for(int i=0;i<2*n;i++)
    {
        long long int xx;
        cin>>xx;
        if(xx<=200000)
        {
            int x=xx;
            if(primes[x]!=-1)
                comp[x]++;
            else
                tot[x]++;
        }
    }
    int sz=comp.size();
    if(sz>0)
    {
        auto it1=comp.end();
        it1--;
        for(int j=0;j<sz;j++)
        {
            if(it1->second==0)
            {
                it1--;
                continue;
            }
            ans.push_back(it1->first);
            int temp=primes[(it1->first)];
            temp=it1->first/temp;
            if(primes[temp]!=-1)
                comp[temp]--;
            else
                tot[temp]--;
            if(it1->second==0)
                it1--;
        }
    }
    auto it=tot.begin();
    while(ans.size()!=n)
    {
        int temp=it->first;
        if(it->second!=0)
        {
            ans.push_back(temp);
            tot[temp]--;
        }
        else
            it++;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}