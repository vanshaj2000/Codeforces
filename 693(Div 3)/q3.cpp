#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		ll n;
		cin>>n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		vector<ll> dp(n+1,0);
		for(ll i=1;i<=n;i++)
		{
			dp[i]=dp[i]+v[i-1];
			if(i+v[i-1]<=n)
				dp[i+v[i-1]]=max(dp[i+v[i-1]],dp[i]);
		}
		cout<<*max_element(dp.begin(),dp.end())<<endl;
	}
}