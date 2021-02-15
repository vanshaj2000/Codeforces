#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		stack<int> s;
		stack<int> s1;
		string str;
		cin>>str;
		int pos=0;
		int neg=0;
		int q=0;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]==')')
				neg++;
			else if(str[i]=='(')
				pos++;
			else
				q++;
		}
		int t=abs(abs(pos-neg)-q);
		int j;
		int k;
		for(j=0;j<str.size();j++)
		{
			if(s.size()==0&&str[j]==')')
				break;
			if(str[j]==')')
				s.pop();
			else
				s.push(1);
		}
		for(k=0;k<str.size();k++)
		{
			if(s1.size()==0&&str[str.size()-k-1]=='(')
				break;
			if(str[str.size()-k-1]=='(')
				s1.pop();
			else
				s1.push(1);
		}
		if(q!=0)
		{
			if(abs(pos-neg)<=q&&t%2==0&&j==(str.size())&&k==str.size())
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
		{
			if(j==str.size()&&pos-neg==0&&k==str.size())
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}