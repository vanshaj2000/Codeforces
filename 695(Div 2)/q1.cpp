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
		ll x=9;
		if(n>1)	
			cout<<"98";
		else
			cout<<"9";
			for(ll i=2;i<n;i++)
			{
				cout<<x;
				x++;
				if(x>9)
					x=0;
			}
		/*else
		{
			x=n;
			while(x>=1)
			{
				if(x-10>=1)
					x=x-10;
				else
					break;
			}
			ll y=9;
			for(ll i=n;i>=x;i--)
			{
				cout<<y;
				y--;
				if(y==-1)
					y=9;
			}
			y=0;
			for(ll i=1;i<x;i++)
			{
				cout<<y;
				y++;
				if(y==10)
					y=0;
			}
		}*/
		cout<<endl;
	}
}