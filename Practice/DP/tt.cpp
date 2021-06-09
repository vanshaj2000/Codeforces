#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
void dfs(int s,vector<bool> &visited,vector<int> &A,vector<int> &B)
{
	visited[s]=true;
	for(int i=0;i<A.size();i++)
	{
		if(visited[i]==true)
			continue;
		if((A[s]<A[i]&&B[s]>A[i])||(A[s]<B[i]&&B[s]>B[i]))
			dfs(i,visited,A,B);
	}
}
int32_t main()
{
   IOS;
   int n,m,k,y,z,c,count=0,ans=0,temp=0,flag=0;
   cin>>n;
   vector<int> A,B;
   for(int i=0;i<n;i++)
    {
		int a,b,x;
        cin>>x>>a>>b;
        if(x==1)
        {
           A.push_back(a);
           B.push_back(b);
        } 
        else
        {
           vector<bool> vis(n,false);
           dfs(a-1,vis,A,B);
           if(vis[b-1]==true)
        		cout<<"YES"<<endl;
           else
            	cout<<"NO"<<endl;
        }  
    }
  return 0;
}