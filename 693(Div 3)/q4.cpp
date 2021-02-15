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
		priority_queue<ll> even;
		priority_queue<ll> odd;
		for(ll i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			if(x%2==0)
				even.push(x);
			else
				odd.push(x);
		}
		even.push(0);
		odd.push(0);
		ll al=0;
		ll bob=0;
		for(ll i=0;i<n;i++)
		{
			if(i%2==0)
			{
				if(even.top()>odd.top())
				{
					ll t=even.top();
					al=al+t;
					even.pop();
				}
				else
					odd.pop();
			}
			else
			{
				if(even.top()<odd.top())
				{
					ll t=odd.top();
					bob=bob+t;
					odd.pop();
				}
				else
					even.pop();
			}
		}
		if(al>bob)
			cout<<"Alice"<<endl;
		else if(al==bob)
			cout<<"Tie"<<endl;
		else
			cout<<"Bob"<<endl;
	}
}