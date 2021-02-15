#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool myCmp(pair<ll,ll> p1,pair<ll,ll> p2)
{
	return p1.first>p2.first||(p1.first==p2.first&&p1.second>p2.second);
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		ll n;
		cin>>n;
		vector<pair<ll,ll>> con;
		map<pair<ll,ll>,ll> mp;
		for(ll i=0;i<n;i++)
		{
			ll a,b;
			pair<ll,ll> pr;
			cin>>a>>b;
			pr.first=max(a,b);
			pr.second=min(a,b);
			con.push_back(pr);
			mp[pr]=i+1;
		}
		vector<ll> ans(n,-1);
		vector<pair<ll,ll>> copy=con;
		sort(con.begin(),con.end(),myCmp);
		/*for(ll i=0;i<n;i++)
		{
			cout<<con[i].first<<" "<<con[i].second<<endl;
		}*/
		vector<ll> mine(n);
		for(ll i=0;i<n;i++)
		{
			mine[i]=con[i].second;
		}
		for(ll i=0;i<n-1;i++)
		{
			int j=0;
			for(int k=i;k<n-1;k++)
			{
				if(con[k].first==con[k+1].first)
					j++;
				else
					break;
			}
			vector<ll>::iterator it=min_element(mine.begin()+i+1+j,mine.end());
			ll ind=it-mine.begin();
			if(ind<n)
			{
				if(con[i].second>con[ind].second)
					ans[mp[con[i]]-1]=mp[con[ind]];
			}
		}

		for(ll i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
}