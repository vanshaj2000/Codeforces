#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		vector<int> arr;
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			arr.push_back(x);
		}
		if(arr[0]+arr[1]>arr[n-1])
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<"1 2 "<<n<<endl;
		}
	}
}