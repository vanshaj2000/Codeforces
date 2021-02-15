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
		ll maxs=0;
		ll mins=0;
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
			if(v[i]%x==0)
				maxs=maxs+v[i]/x;
			else
				maxs=maxs+v[i]/x+1;
			mins=mins+v[i];
		}
		if(mins%x==0)
			mins=mins/x;
		else
			mins=mins/x+1;
		cout<<mins<<" "<<maxs<<endl;
	}
}