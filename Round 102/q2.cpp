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
		string s1,s2;
		cin>>s1>>s2;
		ll n1=s1.size();
		ll n2=s2.size();
		if(n1<n2)
		{
			string t=s1;
			s1=s2;
			s2=t;
		}
		n1=s1.size();
		n2=s2.size();
		ll x=lcm(n1,n2);
		string te=s1;
		string te2=s2;
		while(s1.size()!=x)
			s1=s1+te;
		while(s2.size()!=x)
			s2=s2+te2;
		if(s1==s2)
			cout<<s1<<endl;
		else
			cout<<"-1"<<endl;
	}
}