#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int r,g,b,w;
		int ch=0;
		int count;
		cin>>r>>g>>b>>w;
		if(w%2==0)
		{
			int ct=0;
			if(r%2==0)
				ct++;
			if(g%2==0)
				ct++;
			if(b%2==0)
				ct++;
			if(ct>=2)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				if(ct==0&&r>0&&g>0&&b>0)
				{
					cout<<"YES"<<endl;
				}
				else
				{
					cout<<"NO"<<endl;
				}
			}
		}
		else
		{
			int ct=0;
			if(r%2==0)
				ct++;
			if(g%2==0)
				ct++;
			if(b%2==0)
				ct++;
			if(ct==3)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				if(ct==1&&r>0&&g>0&&b>0)
				{
					cout<<"YES"<<endl;
				}
				else
				{
					if(ct==0&&r>0&&g>0&&b>0)
					{
						cout<<"YES"<<endl;
					}
					else
					{
						cout<<"NO"<<endl;
					}
				}
			}
		}
	}
}