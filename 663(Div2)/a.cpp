#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> ans;
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int n;
		cin>>n;
		string s="";
		for(int j=1;j<=n;j++)
		{
			string s2=to_string(j);
			s=s+s2;
			s=s+" ";
		}
		s=s-" ";
		cout<<s<<endl;
	}
}