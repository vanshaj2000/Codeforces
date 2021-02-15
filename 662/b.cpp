#include<bits/stdc++.h>
using namespace std;
int recCheck(vector<int> v1)
{
	v1.erase(remove(v1.begin(), v1.end(), 0), v1.end());
	v1.erase(remove(v1.begin(), v1.end(), 1), v1.end());
	v1.push_back(0);
	v1.push_back(0);
	if(v1[0]>=2)
	{
		if(v1[1]>=2||v1[0]>=4)
			return 1;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}
int seqCheck(vector<int> v1)
{
	v1.erase(remove(v1.begin(), v1.end(), 0), v1.end());
	for(int i=0;i<v1.size();i++)
	{
		if(v1[i]>=4)
		{
			vector<int> copy=v1;
			copy[i]=copy[i]-4;
			int a=recCheck(copy);
			if(a==1)
				return 1;
		}
	}
	return 0;
}
int main()
{
	vector<int> ans;
	vector<int> vet(100000,0);
	vector<int> copy;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ans.push_back(x);
		vet[x]++;
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		char ch;
		int y;
		cin>>ch;
		cin>>y;
		int z=y;
		if(ch=='-')
		{
			vet[z]--;
		}
		else
		{
			vet[z]++;
		}

		int b=seqCheck(vet);
		if(b==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}