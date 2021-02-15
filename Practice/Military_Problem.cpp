#include<bits/stdc++.h>
using namespace std;
bool sortRow(int a,int b)
{
	return a<b;
}
void dfs(vector<vector<int>> &v,vector<int> &ans,vector<bool> &vis,int ind,vector<vector<int>> &d)
{
	vis[ind]=true;
	d[ind][0]=ans.size();
	//cout<<ans.size()<<endl;
	ans.push_back(ind);
	for(int i=0;i<v[ind].size();i++)
	{
		int u=v[ind][i];
		if(vis[u]==false)
			dfs(v,ans,vis,u,d);
	}
	d[ind][1]=ans.size()-1;
}
int main()
{
	int n,q;
	cin>>n>>q;
	vector<vector<int>> v(n);
	for(int i=1;i<=n-1;i++)
	{
		int a;
		cin>>a;
		a--;
		v[a].push_back(i);
	}
	for(int i=0;i<n;i++)
		sort(v[i].begin(),v[i].end(),sortRow);
	vector<int> ans;
	vector<bool> vis(n,false);
	vector<vector<int>> d(n,vector<int>(2));
	dfs(v,ans,vis,0,d);
	for(int i=0;i<q;i++)
	{
		int u,k;
		cin>>u>>k;
		u--;
		if((d[u][1]-d[u][0])<k-1)
			cout<<"-1"<<endl;
		else
			cout<<ans[d[u][0]+k-1]+1<<endl;
	}
}