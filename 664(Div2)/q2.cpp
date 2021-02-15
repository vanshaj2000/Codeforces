#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	//cout<<n<<" "<<m<<endl;
	int x1,y1;
	cin>>x1>>y1;
	int x,y;
	x=x1;
	y=y1;
	int j;
	for(int i=x;i>=1;--i)
	{
		for(j=y;j>=1;--j)
			cout<<i<<" "<<j<<endl;
		for(int k=y+1;k<=m;++k)
		{
			j=k;
			cout<<i<<" "<<k<<endl;
		}
		y=j;
	}
	for(int i=x+1;i<=n;++i)
	{
		for(j=y;j>=1;--j)
			cout<<i<<" "<<j<<endl;
		for(int k=y+1;k<=m;++k)
		{
			j=k;
			cout<<i<<" "<<j<<endl;
		}
		y=j;
	}
}