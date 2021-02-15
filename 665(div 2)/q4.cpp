#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define modulo 1000000007
void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
ll dfsCount(vector<vector<ll>> &v,vector<bool> &vis,vector<ll> &ans,ll ind,ll n)
{
	vis[ind]=true;
	ll count=1;
	for(ll i=0;i<v[ind].size();i++)
	{
		if(vis[v[ind][i]]==false)
		{
			ll t=dfsCount(v,vis,ans,v[ind][i],n);
			ans.push_back(t*(n-t));
			count=count+t;
		}
	}
	return count;
}
int32_t main()
{
	IOS();
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
	ll test;
	cin>>test;
	while(test--)
	{
		ll n;
		cin>>n;
		vector<vector<ll>> v(n);
		for(int i=0;i<n-1;i++)
		{
			ll a,b;
			cin>>a>>b;
			a--;
			b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		ll m;
		cin>>m;
		vector<ll> fact(m);
		for(int i=0;i<m;i++)
			cin>>fact[i];
		sort(fact.begin(),fact.end(),greater<ll>());
		if(m<n-1)
		{
			for(ll i=0;i<n-m-1;i++)
				fact.push_back(1);
		}
		else
		{
			for(ll i=0;i<m-n+1;i++)
			{
				fact[1]=(fact[0]*fact[1])%modulo;
				fact.erase(fact.begin());
			}
		}
		vector<ll> ans;
		vector<bool> vis(n,false);
		int temp=dfsCount(v,vis,ans,0,n);
		sort(ans.begin(),ans.end(),greater<ll>());
		for(ll i=0;i<n-1;i++)
        	ans[i]=ans[i]%modulo;
    	ll ans1=0;
    	for(ll i=0;i<n-1;i++)
        	ans1=(ans1+((ans[i]*fact[i])%modulo))%modulo;
        cout<<ans1<<endl;
	}
}