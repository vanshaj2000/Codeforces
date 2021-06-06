#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fast_cin();
    int n,sum=0,od=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int curr=v[0];
    for(int i=1;i<n;i++)
        curr=__gcd(curr,v[i]);
    for(int i=0;i<n;i++)
        v[i]=v[i]/curr,sum+=v[i],od+=v[i]%2;
    if(od%2)
    {
        cout<<"0";
        return 0;
    }
    sum=sum/2;
    vector<vector<bool>> kp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<=n;i++)
        kp[i][0]=true;
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=n;j++)
        {
            kp[j][i]=kp[j-1][i];
            if(i>=v[j-1])
                kp[j][i]=(kp[j][i])||(kp[j-1][i-v[j-1]]);
        }
    }
    if(kp[n][sum])
    {
        for(int i=0;i<n;i++)
        {
            if(v[i]%2)
                cout<<"1"<<endl<<i+1,i+=n;
        }
    }
    else
        cout<<"0";
    return 0;
}