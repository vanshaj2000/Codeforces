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
		ll n;
		cin>>n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		ll count=0;
		ll ans;
		vector<int> hv(n);
		for(ll i=1;i<n-1;i++)
		{
			if((v[i]>v[i+1]&&v[i]>v[i-1])||(v[i]<v[i-1]&&v[i]<v[i+1]))
			{
				hv[i]=1;
				count++;
			}
		}
		ans=count;
		for(ll i=1;i<n-1;i++)
		{
			if(hv[i]==1)
			{
				if(i==1)
				{
					ll temp=v[i];
					v[i]=v[0];
					ll change=1;
					if((v[i+1]>v[i+2]&&v[i+1]>v[i])||(v[i+1]<v[i]&&v[i+1]<v[i+2]))
					{
						if(hv[i+1]==0)
							change--;
					}
					ans=min(ans,count-change);
					v[i]=v[i+1];
					change=1;
					if(hv[i+1]==1)
						change++;
					ans=min(ans,count-change);
					v[i]=temp;
				}
				else if(i==n-2)
				{
					ll temp=v[i];
					v[i]=v[n-1];
					ll change=1;
					if((v[i-2]>v[i]&&v[i-1]>v[i-2])||(v[i-1]<v[i-2]&&v[i-1]<v[i]))
					{
						if(hv[i-1]==0)
							change--;
					}
					ans=min(ans,count-change);
					v[i]=v[i-1];
					change=1;
					if(hv[i-1]==1)
						change++;
					ans=min(ans,count-change);
					v[i]=temp;
				}
				else
				{
					ll temp=v[i];
					v[i]=v[i-1];
					ll change=1;
					if((v[i+1]>v[i+2]&&v[i+1]>v[i])||(v[i+1]<v[i]&&v[i+1]<v[i+2]))
					{
						if(hv[i+1]==0)
							change--;
					}
					else
					{
						if(hv[i+1]==1)
							change++;
					}
					if(hv[i-1]==1)
						change++;
					ans=min(ans,count-change);
					v[i]=v[i+1];
					change=1;
					if((v[i-1]>v[i]&&v[i-1]>v[i-2])||(v[i-1]<v[i-2]&&v[i-1]<v[i]))
					{
						if(hv[i-1]==0)
							change--;
					}
					else
					{
						if(hv[i-1]==1)
							change++;
					}
					if(hv[i+1]==1)
						change++;
					ans=min(ans,count-change);
					v[i]=temp;
				}
			}
		}
		if(count==0)
			cout<<"0"<<endl;
		else
			cout<<ans<<endl;
	}
}