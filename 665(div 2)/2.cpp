#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int x1,y1,z1;
		int x2,y2,z2;
		cin>>x1>>y1>>z1;
		cin>>x2>>y2>>z2;
		int sum=x1+y1+z1;
		int ans=0;
		for(int i=0;i<z1;i++)
		{
			if(y2>0)
			{
				ans=ans+2;
				y2--;
			}
			else
			{
				if(x2>0)
				{
					x2--;
				}
				else
				{
					y2--;
				}
			}
		}
		for(int i=0;i<y1;i++)
		{
			if(y2>0)
			{
				z2--;
			}
			else
			{
				if(z2>0)
				{
					y2--;
				}
				else
				{
					ans=ans-2;
					x2--;
				}
			}
		}
		cout<<ans<<endl;
	}
}