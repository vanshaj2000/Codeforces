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
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	int x=n/2;
    	if(s[0]=='1')
    	{
    		int c=0;
    		int flag=1;
    		for(int i=1;i<n;i++)
    		{
    			if(s[i]=='1')
    				flag=1;
    			else
    			{
    				if(flag==1)
    				{
    					c++;
    				}
    				flag=0;
    			}
    		}
    		c--;
    		x--;
    		int ans=x-c;
    		cout<<ans<<endl;
    	}
    	else
    	{
    		int c=0;
    		int flag=1;
    		for(int i=1;i<n;i++)
    		{
    			if(s[i]=='0')
    				flag=1;
    			else
    			{
    				if(flag==1)
    				{
    					c++;
    				}
    				flag=0;
    			}
    		}
    		c--;
    		x--;
    		int ans=x-c;
    		cout<<ans<<endl;
    	}
    }
    return 0;
}