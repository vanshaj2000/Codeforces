#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
#define N 1000001
bool primes[N];
void sieve(int n)
{
    memset(primes,true,n+1);
    primes[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(primes[i])
        {
            for(int j=i*i;j<=n;j+=i)
                primes[j]=false;
        }
    }
}
int32_t main()
{
    fast_cin();
    int a,b,k,fs,en;
    cin>>a>>b>>k;
    sieve(b);
    int curr=0;
    for(int i=a;i<=b;i++)
    {
        if(primes[i])
        {
            if(curr==0)
                fs=i;
            if(curr==k-1)
                en=i;
            curr++;
        }
    }
    //cout<<curr<<endl;
    if(curr<k)
    {
        cout<<"-1";
        return 0;
    }
    int s=a,e=en,th=k;
    while(e<=b)
    {
        if(th>=k)
        {
            s++,e++;
            th+=(primes[e]-primes[s-1]);
        }
        else
        {
            s--;
            th+=primes[s];
        }
    }
    cout<<e-s+1;
}