#include<bits/stdc++.h>
using namespace std;
int teams;
int check(vector<int> vt,int sum,int r)
{
	int s=vt.size();
	int s2=s/2;
	for(int i=0;i<s2;i++)
	{
		for(int j=s2;j<s;j++)
		{
			if((vt[i]+vt[j])==sum)
			{
				return check(vt,sum,r++);
			}
		}
	}
	return r;
}
void func(vector<int> vec)
{
	int s=vec.size();
	int m=s/2;
	int l=vec[s-1]*2;
	for(int i=2;i<l;i++)
	{
		int c=check(vec,i,0);
		if(c>teams)
		{
			teams=c;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	int tc=0;
	vector<int> ans;
	while(tc<t)
	{
		tc++;
		int n;
		cin>>n;
		teams=0;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		func(v);
		ans.push_back(teams);
	}
	for(int i=0;i<t;i++)
	{
		cout<<ans[i]<<endl;
	}
}
