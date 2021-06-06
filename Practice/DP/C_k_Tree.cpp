#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int mod=1000000007;
int getSum(int n,int k,unordered_map<int,int> &ump)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(ump[n]!=0)
        return ump[n];
    int ret=0;
    for(int i=1;i<=k;i++)
        ret=(ret+getSum(n-i,k,ump))%mod;
    return ump[n]=ret;
}
int32_t main()
{
    fast_cin();
    int n,k,d;
    cin>>n>>k>>d;
    unordered_map<int,int> ump1,ump2;
    cout<<(getSum(n,k,ump1)-getSum(n,d-1,ump2)+mod)%mod;
    return 0;
}