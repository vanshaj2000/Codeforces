#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
    	int n;
    	cin>>n;
    	int arr[2];
    	arr[0]=0;
    	arr[1]=0;
    	vector<int> v;
    	for(int j=0;j<n;j++)
    	{
    		int x;
    		cin>>x;
    		arr[x]++;
    		v.push_back(x);
    	}
    	if(arr[1]<=n/2)
    	{
    		cout<<n-arr[1]<<endl;
    		for(int k=0;k<n-arr[1];k++)
    		{
    			cout<<"0";
    			if(k<(n-arr[1]-1))
    				cout<<" ";
    		}
    		cout<<endl;
    	}
    	else
    	{
    		if((n/2)%2==0)
    		{
    			cout<<n/2<<endl;
	    		for(int k=0;k<n/2;k++)
	    		{
	    			cout<<"1";
	    			if(k<n/2-1)
	    				cout<<" ";
	    		}
	    		cout<<endl;
    		}
    		else
    		{
    			cout<<n/2+1<<endl;
	    		for(int k=0;k<n/2+1;k++)
	    		{
	    			cout<<"1";
	    			if(k<n/2)
	    				cout<<" ";
	    		}
	    		cout<<endl;
    		}
    	}
    }
    return 0;
}