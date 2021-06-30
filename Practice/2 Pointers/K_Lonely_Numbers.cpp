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
    int maxi=1000000;
    //cout<<maxi<<endl;
    SieveOfEratosthenes(maxi);
    vector<int> dp(maxi+1,0);
    for(int i=2;i<=maxi;i++)
    {
        dp[i]+=dp[i-1];
        if(!prime[i])
            dp[i]++;
        else if(i*i<=maxi)
            dp[i*i]++;
    }
    int t;
    cin>>t;
    //cout<<t<<endl;
    for(int j=0;j<t;j++)
    {
        int n;
        cin>>n;
        //cout<<n<<endl;
        cout<<n-dp[n]<<endl;
    }
    return 0;
}