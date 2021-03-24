#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> ans;
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int c=0;
		int n,m;
		cin>>n>>m;
		char arr[n][m];
		char *ptr=&arr[0][0];
		for(int j=1;j<=n*m;j++)
		{
			char ch;
			cin>>ch;
			*ptr=ch;
			if(j%m==0)
			{
				if(*ptr=='R')
					c++;
			}
			else
			{
				if((n*m-j)<m)
				{
					if(*ptr=='D')
						c++;
				}
			}
		}
		cout<<c<<endl;
	}
}