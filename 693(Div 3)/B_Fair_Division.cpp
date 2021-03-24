#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int c1=0;
		int c2=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x==1)
				c1++;
			else
				c2++;
		}
		if(c1%2==1)
			cout<<"NO"<<endl;
		else
		{
			if(c1==0)
			{
				if(c2%2==0)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
			else
				cout<<"YES"<<endl;
		}
	}
}