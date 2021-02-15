#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> v(n);
		map<ll,int> mp;
		vector<ll> type;
		int ans=0;
		int mx=-1; 
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(mp[v[i]]==0)
			{
				mp[v[i]]++;
				mx=max(mx,mp[v[i]]);
				type.push_back(v[i]);
			}
			else
			{
				mp[v[i]]++;
				mx=max(mx,mp[v[i]]);
			}
		}
		int a=0;
		for(int i=0;i<type.size();i++)
		{
			if(mp[type[i]]==mx)
				a++;
		}
		cout<<(n-mx-a+1)/(mx-1)<<endl;
	}
}