#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int32_t main()
{
    fast_cin();
    int n,maxi=0;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    vector<int> fr(n+1,0),bk(n+1,0);
    for(int i=0;i<n;i++)
        fr[i+1]+=(fr[i]+(a[i]*b[i]));
    maxi=fr[n];
    for(int i=1;i<n;i++)
    {
        int sum=a[i]*b[i],sum2=0;
        for(int j=1;i-j>=0&&((i+j)<n);j++)
        {
            int l=i-j,r=i+j;
            sum+=(a[i-j]*b[i+j]+a[i+j]*b[i-j]);
            int temp=fr[l]+sum+fr[n]-fr[r+1];
            maxi=max(maxi,temp);
        }
        for(int j=1;i-j>=0&&((i+j)<=n);j++)
        {
            int l=i-j,r=i+j-1;
            sum2+=a[r]*b[l]+a[l]*b[r];
            int temp=sum2+fr[l]+fr[n]-fr[r+1];
            maxi=max(maxi,temp);
        }
    }
    cout<<maxi;
    return 0;
}