#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll n;
	cin>>n;
	vector<ll> type;
	vector<ll> mp(100001,0);
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		if(mp[x]==0)
		{
			type.push_back(x);
			mp[x]++;
		}
		else
			mp[x]++;
	}
	ll t;
	cin>>t;
	while(t--)
	{
		char ch;
		ll y;
		cin>>ch>>y;
		//cout<<y<<endl;
		if(ch=='+')
		{
			if(mp[y]==0)
			{
				type.push_back(y);
				mp[y]++;
			}
			else
			{
				if(mp[y]==-1)
					mp[y]=mp[y]+2;
				else
					mp[y]++;
			}
		}
		else
		{
			mp[y]--;
			if(mp[y]==0)
				mp[y]=-1;
		}
		if(checkS(type,mp))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}