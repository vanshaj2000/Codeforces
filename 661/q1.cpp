#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		int min=INT_MAX;
		int m=INT_MIN;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			m=max(m,v[i]);
			min=min(min,v[i]);
		}
		if(m-min<=1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}