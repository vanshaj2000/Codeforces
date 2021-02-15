#include<bits/stdc++.h>
using namespace std;
int dfsSingle(vector<vector<int>> &v,vector<bool> &vis,int ind,vector<int> &count)
{
	int sum=0;
	int max1=1;
	vis[ind]=true;
	for(int i=0;i<v[ind].size();i++)
	{
		if(vis[v[ind][i]]==false)
		{
			int val=dfsSingle(v,vis,v[ind][i],count)+1;
			sum=sum+val;
			max1=max(val,max1);
		}
	}
	int max2=v.size()-1-sum;
	count[ind]=max(max1,max2);
	return sum;
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		vector<vector<int>> v(n);
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int mini=INT_MAX;
		vector<bool> vis(n,false);
		vector<int> ans(n);
		int x=dfsSingle(v,vis,0,ans);
		//for(int i=0;i<n;i++)
			//cout<<ans[i]<<endl;
		x=*min_element(ans.begin(),ans.end());
		vector<int> centroids;
		for(int i=0;i<n;i++)
		{
			if(ans[i]==x)
				centroids.push_back(i);
		}
		if(centroids.size()==1)
		{
			cout<<centroids[0]+1<<" "<<v[centroids[0]][0]+1<<endl;
			cout<<centroids[0]+1<<" "<<v[centroids[0]][0]+1<<endl;
		}
		else
		{
			vector<bool> visited(n,false);
			visited[centroids[0]]=true;
			for(int i=0;i<v[centroids[1]].size();i++)
			{
				if(visited[v[centroids[1]][i]]==0)
				{
					cout<<v[centroids[1]][i]+1<<" "<<centroids[1]+1<<endl;
					cout<<centroids[0]+1<<" "<<v[centroids[1]][i]+1<<endl;
					break;
				}
			}
		}
	}
}