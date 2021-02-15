#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		long long int ans=0;
		int n;
		long long int k;
		cin>>n>>k;
		int max=INT_MAX;
		for(int j=0;j<n;j++)
		{
			long long int x;
			cin>>x;
			if(k-j-1>=0&&(k-j-1)%x==0)
			{
				int a=(k-j-1)/x;
				if(a<max)
				{
					max=a;
					ans=x;
				}

			}
		}
		if(max==INT_MAX)
			cout<<"-1";
		else
			cout<<ans;
	}
}