#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		string s;
		cin>>s;
		int l=s.size();
		vector<int> ans;
		int c=0;
		for(int j=0;j<l-1;j++)
		{
			if(s[j]=='1')
			{
				c++;
			}
			else
			{
				if(c!=0)
				{
					ans.push_back(c);
					c=0;
				}
			}
		}
		if(s[l-1]=='1')
		{
			c++;
			ans.push_back(c);
		}
		else
		{
			if(c!=0)
			{
				ans.push_back(c);
			}
		}
		int al=0;
		sort(ans.begin(),ans.end());
		reverse(ans.begin(),ans.end());
		for(int j=0;j<ans.size();j=j+2)
		{
			al=al+ans[j];
		}
		cout<<al<<endl;
	}
}