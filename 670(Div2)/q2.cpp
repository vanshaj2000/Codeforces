#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int j=0;j<T;j++)
    {
    	long long int n;
    	cin>>n;
    	vector<long long int> v;
    	long long int ans;
    	for(int i=0;i<n;i++)
    	{
    		long long int x;
    		cin>>x;
    		v.push_back(x);
    	}
    	sort(v.begin(),v.end());
    	if(v[n-1]>=0)
    	{
    		ans=v[n-1];
	    	if(v[0]*v[1]>v[n-2]*v[n-3])
	    	{
	    		ans=ans*v[0]*v[1];
	    		if(v[2]*v[3]>=v[n-2]*v[n-3])
	    		{
	    			ans=ans*v[2]*v[3];
	    		}
	    		else
	    		{
	    			ans=ans*v[n-2]*v[n-3];
	    		}
	    	}
	    	else
	    	{
	    		ans=ans*v[n-2]*v[n-3];
	    		if(v[0]*v[1]>=v[n-4]*v[n-5])
	    		{
	    			ans=ans*v[0]*v[1];
	    		}
	    		else
	    		{
	    			ans=ans*v[n-4]*v[n-5];
	    		}
	    	}
    	}
    	else
    	{
    		ans=v[n-1]*v[n-2]*v[n-3]*v[n-4]*v[n-5];
    	}
    	cout<<ans<<endl;	
    }
    return 0;
}