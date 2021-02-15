#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define modulo 1000000007
void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int32_t main()
{
	IOS();
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
	ll test;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> per(k+1);
    	for(int i=1;i<2*k-n;i++)
        	per[i] = i;
    	int c=k;
    	for(int i=2*k-n;i<=k;i++)
    	{
        	per[i]=c;
        	c--;
    	}
    	for(int i=1;i<=k;i++)
        	cout<<per[i]<<" ";
    	cout<<endl;
	}
}