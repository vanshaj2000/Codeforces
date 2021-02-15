#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int c=0;
		int n;
		cin>>n;
		vector<int> arr;
		string s;
		cin>>s;
		unsigned int opsize = pow(2, n);
		vector<int> ans;
		for (int counter = 1; counter < opsize; counter++) 
    	{
    		int k=0;
    		vector<int> sq;
        	for (int j = 0; j < n; j++) 
        	{
            	if (counter & (1<<j))
            	{
            		int x=s[j]-48;
            		ans.push_back(x);
            		sq.push_back(j);
            	}

        	}
        	int sum=0;
        	int count=0;
        	int ch=sq[0];
        	sort(sq.begin(),sq.end());
        	for(int j=0;j<ans.size();j++)
        	{
        		sum=sum+ans[j];
        		if(ch==sq[j])
        		{
        			ch=ch+1;
        		}
        		else
        		{
        			count++;
        		}
        	}
        	if(sum==ans.size()&&count==0)
        	{
        		c++;
        	}
        	ans.clear();
    	}
    	cout<<c<<endl;
	}
}