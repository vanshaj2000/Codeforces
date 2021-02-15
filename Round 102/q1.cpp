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
		ll n,d;
		cin>>n>>d;
		vector<ll> v;
		for(ll i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		if(v[0]+v[1]<=d)
			cout<<"YES"<<endl;
		else if(v[n-1]<=d)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}