#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
bool prime[1000001];
void SieveOfEratosthenes(int n)
{
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++)
    {
        if(prime[p]==true)
        {
            for(int i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
}
int32_t main()
{
    fast_cin();
    //cout<<"Hello"<<endl;
    int t;
    cin>>t;
    SieveOfEratosthenes(100000);
    //cout<<"Hell"<<endl;
    for(int k=0;k<t;k++)
    {
        int n,ans=-1,vet;
        cin>>n;
        int x=sqrt(n);
        for(int i=2;i<=x;i++)
        {
            if(!prime[i])
                continue;
            int c=0,tt=n;
            while((tt%i)==0)
                c++,tt/=i;
            if(ans<c)
                ans=c,vet=i;
        }
        if(ans<=1)
            cout<<"1"<<endl<<n<<endl;
        else
        {
            cout<<ans<<endl;
            for(int i=0;i<ans-1;i++)
                cout<<vet<<" ",n/=vet;
            cout<<n<<endl;
        }
    }
    return 0;
}