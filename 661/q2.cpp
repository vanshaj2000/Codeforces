#include<bits/stdc++.h>
using namespace std;
int moves;
vector<int> s;
int check(vector<int> v1,vector<int> v2)
{
	for(int i=0;i<v1.size();i++)
	{
		if(v1[i]!=v2[i])
			return 0;
	}
	return 1;
}
void func(vector<int> a1,vector<int> b1,int m)
{
	int b=check(a1,b1);
	if(b==1)
	{
		if(m<moves)
		{
			moves=m;
		}
	}
	for(int i=0;i<a1.size();i++)
	{
		vector<int> ac1=a1;
		vector<int> ac2=a1;
		vector<int> bc1=b1;
		vector<int> bc2=b1;
		ac1[i]--;
		int m1=m;
		m1++;
		if(ac1[i]>=0&&m1<moves)
			func(ac1,b1,m1);
		bc1[i]--;
		int m2=m;
		m2++;
		if(bc1[i]>=0&&m2<moves)
			func(a1,bc1,m2);
		ac2[i]--;
		bc2[i]--;
		int m3=m;
		m3++;
		if(ac2[i]>=0&&bc2[i]>=0&&m3<moves)
			func(ac2,bc2,m3);
	}
}
int main()
{
	s.clear();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		moves=INT_MAX;
		int n;
		cin>>n;
		vector<int> a;
		vector<int> b;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			a.push_back(x);
		}
		for(int j=0;j<n;j++)
		{
			int y;
			cin>>y;
			b.push_back(y);
		}
		func(a,b,0);
		if(moves!=0)
			moves--;
		s.push_back(moves);
	}
	for(int i=0;i<t;i++)
	{
		cout<<s[i]<<endl;
	}
}
