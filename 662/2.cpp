#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	cin>>x>>y;
	int arr[n][m];
	for(int i=x;i<=n;i++)
	{
		for(int j=y;j<=m;j++)
		{
		    arr[i][j]=1;
			cout<<i<<" "<<j<<endl;
		}
	}
	for(int i=x;i>=1;i--)
	{
		for(int j=y;j>=1;j--)
		{
			if(arr[i][j]!=1)
			{
			    arr[i][j]=1;
			    cout<<i<<" "<<j<<endl;
			}
		}
	}
	for(int i=x;i>=1;i--)
	{
		for(int j=y;j<=m;j++)
		{
			if(arr[i][j]!=1)
			{
			    arr[i][j]=1;
			   cout<<i<<" "<<j<<endl;
			}
		}
	}
	for(int i=x;i<=n;i++)
	{
		for(int j=y;j>=1;j--)
		{
			if(arr[i][j]!=1)
			{
			    arr[i][j]=1;
			    cout<<i<<" "<<j<<endl;
			}
		}
	}
}