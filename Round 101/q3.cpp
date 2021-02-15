#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vector<ll> h(n);
		for(ll i=0;i<n;i++)
			cin>>h[i];
		//cout<<n<<endl;
		vector<bool> bc(n,true);
		vector<ll> ans(n);
		ans[0]=h[0];
		ans[n-1]=h[n-1];
		for(ll i=1;i<n-1;i++)
		{
			if(bc[i-1]==true)
			{
				ll cons=h[i]-ans[i-1];
				if((2-cons)<=2*k&&k>=(cons+1))
				{
					if(h[i+1]>h[i])
						ans[i]=min(ans[i-1]-1+k,k-1+h[i]);
					else
						ans[i]=max(ans[i-1]-k+1,h[i]);
				}
				else
					bc[i]=false;
			}
			else
				bc[i]=false;
		}
		if(bc[n-2]==true)
		{
			if(abs(ans[n-1]-ans[n-2])<=k-1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}