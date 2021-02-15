#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		ll w,h,n;
		cin>>w>>h>>n;
		ll cw=0;
		ll ch=0;
		while(w%2==0)
		{
			w=w/2;
			cw++;
		}
		while(h%2==0)
		{
			h=h/2;
			ch++;
		}
		ll ans=pow(2,ch)*pow(2,cw);
		if(ans>=n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}