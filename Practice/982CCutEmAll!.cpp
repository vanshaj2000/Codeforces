#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &v,vector<bool>& vis,int ind,vector<int> &num)
{
	vis[ind]=true;
	int ans=1;
	for(int i=0;i<v[ind].size();i++)
	{
		int u=v[ind][i];
		if(vis[u]==false)
			ans=ans+dfs(v,vis,u,num);
	}
	num[ind]=ans;
	return ans;
}
int sol(vector<vector<int>> &v,vector<bool>& check,int ind,vector<int> &num)
{
	check[ind]=true;
	int ans=0;
	if(num[ind]<=2)
		return 0;
	else
	{
		for(int i=0;i<v[ind].size();i++)
		{
			int u=v[ind][i];
			if(check[u]==false)
				ans=ans+sol(v,check,u,num)+1-(num[u]%2);
		}
		return ans;
	}
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> v(n);
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(n%2!=0)
		cout<<"-1";
	else
	{
		vector<int> num(n,0);
		vector<bool> vis1(n,false);
		int x=dfs(v,vis1,0,num);
		vis1.clear();
		vector<bool> vis(n,false);
		cout<<sol(v,vis,0,num);
	}
}