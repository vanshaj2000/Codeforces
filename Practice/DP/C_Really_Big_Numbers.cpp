#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int getSum(int y)
{
    int ret=0;
    while(y>0)
        ret+=y%10,y/=10;
    return ret;
}
int32_t main()
{
    fast_cin();
    int n,ss,fl=0;
    cin>>n>>ss;
    int s=1,e=n;
    while(s<=e)
    {
        int mid=(s+e)/2;
        int temp=getSum(mid);
        //cout<<temp<<endl;
        if(s==e)
        {
            if(mid-temp<ss)
                fl++;
            break;
        }
        else
        {
            if(mid-temp<ss)
                s=mid+1;
            else
                e=mid;
        }
    }
    if(fl)
        cout<<"0";
    else
        cout<<n-s+1;
    return 0;
}