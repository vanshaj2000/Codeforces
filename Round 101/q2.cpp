#include<bits/stdc++.h>
using namespace std;
void func(vector<int> a1,vector<int> a2,int i1,int i2,int sum)
{
	int x=i1;
	int y=i2;
	if(i1<a1.size()&&i2<a2.size())
	{
		func(a1,a2,i1+1,i2+1,sum+a1[x]+a2[y]);
		func(a1,a2,i1,i2+1,sum+a2[y]);
		func(a1,a2,i1+1,i2,sum+a1[x]);
	}
	else
	{
		//cout<<sum<<endl;
		return;
	}
}
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		vector<int> arr;
		int n;
		cin>>n;
		int sum=0;
		vector<int> t1;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			arr.push_back(x);
			sum=sum+x;
			t1.push_back(sum);
		}
		vector<int> arr2;
		int n2;
		cin>>n2;
		sum=0;
		vector<int> t2;
		for(int j=0;j<n2;j++)
		{
			int x;
			cin>>x;
			arr2.push_back(x);
			sum=sum+x;
			t2.push_back(sum);
		}
		int ans=0;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n2;k++)
			{
				//cout<<ans<<endl;
				ans=max(ans,max(t1[j]+t2[k],max(t1[j],t2[k])));
			}
		}
		cout<<ans<<endl;	
	}
}