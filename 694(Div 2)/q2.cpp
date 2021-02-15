#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n);
		ll sum=0;
		for(ll i=0;i<n;i++)
			cin>>v[i];
		ll j=0;
		vector<vector<ll>> dp(n,vector<ll>(2,0));
		for(ll i=0;i<n;i++)
			dp[i][0]=v[i];
		while(dp[j][0]%x==0)
		{
			sum=sum+dp[j][0]*pow(x,dp[j][1]);
			dp[j][0]=dp[j][0]/x;
			dp[j][1]=dp[j][1]+1;
			j++;
			if(j==n)
				j=0;
		}
		for(ll i=0;i<n;i++)
		{
			sum=sum+dp[i][0]*pow(x,dp[i][1]);
		}
		cout<<sum<<endl;
	}
}