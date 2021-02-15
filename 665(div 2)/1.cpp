#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		double n,k;
		cin>>n>>k;
		double y1=(n+k)/2;
		int y2=(n+k)/2;
		double y=y1-y2;
			if(y>0)
			{
				int x=n+1;
				int ans=k-x;
				int y3=(x+k)/2;
				if(ans<=0)
				{
					cout<<"1"<<endl;
				}
				else
				{
					ans++;
					cout<<ans<<endl;
				}
			}
			else
			{
				int x=n;
				int ans=k-x;
				if(ans<=0)
				{
					cout<<"0"<<endl;
				}
				else
				{
					cout<<ans<<endl;
				}
			}
		
	}
}