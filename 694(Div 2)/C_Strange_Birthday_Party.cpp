#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		ll n,m;
		cin>>n>>m;
		vector<ll> k(n);
		vector<ll> c(m);
		for(ll i=0;i<n;i++)
			cin>>k[i];
		for(ll i=0;i<m;i++)
			cin>>c[i];
		sort(k.begin(),k.end(),greater<ll>());
		ll ind=0;
		ll ans=0;
		//cout<<k[0]<<endl;
		for(ll i=0;i<n;i++)
		{
			if(ind<m&&(ind+1)<=k[i]&&c[k[i]-1]>=c[ind])
			{
				//cout<<"hello"<<endl;
				ans=ans+c[ind];
				ind++;
			}
			else
			{
				//cout<<c[k[i]-1]<<endl;
				ans=ans+c[k[i]-1];
			}
		}
		cout<<ans<<endl;
	}
}