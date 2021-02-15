#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y=0;
    int n;
    cin>>n;
    vector<int> ans(n,0);
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
    	mp.insert({i,1});
    }
    for(int i=1;i<n;i++)
    {
    	string s1=to_string(y+1);
    	string s2=to_string(i+1);
    	string q1="? ";
    	string q2="? ";
    	q1=q1+s1;
    	q2=q2+s2;
    	q1=q1+" ";
    	q2=q2+" ";
    	q1=q1+s2;
    	q2=q2+s1;
    	cout<<q1<<endl;
    	cout.flush();
    	int ans1,ans2;
    	cin>>ans1;
    	if(ans1==-1)
    		return 0;
    	cout<<q2<<endl;
    	cout.flush();
    	cin>>ans2;
    	if(ans2==-1)
    		return 0;
    	if(ans1>ans2)
    	{
    		ans[y]=ans1;
    		y=i;
    		mp[ans1]--;
    	}
    	else
    	{
    		ans[i]=ans2;
    		mp[ans2]--;
    	}
    }
    for(int i=1;i<=n;i++)
	{
		if(mp[i]==1)
		{
			ans[y]=i;
		}
	}
	cout<<"!";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<ans[i];
	}
    return 0;
}