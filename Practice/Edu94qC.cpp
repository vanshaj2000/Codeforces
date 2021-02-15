#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		int x;
		cin>>s>>x;
		int n=s.size();
		string w=string(s.size(),'1');
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				if((i-x)>=0)
					w[i-x]='0';
				if((i+x)<n)
					w[i+x]='0';
			}
		}
		string str=w;
		//cout<<w<<endl;
		for(int i=0;i<n;i++)
		{
			if ((i-x>=0&&w[i-x]=='1')||(i+x<n&&w[i+x]=='1'))
            	str[i]='1';
        	else
            	str[i]='0';
		}
		//cout<<str<<endl;
		if(str==s)
			cout<<w<<endl;
		else
			cout<<"-1"<<endl;
	}
}