#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void recur(ll n, vector<pair<ll,ll>> &ans)
{
	if (n == 2)
		return;
	ll y = max(1, (int)sqrt(n) - 1);
	while (y<(n+y-1)/y)
		y++;
	for(ll i=y+1;i<n;i++)
		ans.push_back({i,n});
	ans.push_back({n,y});
	ans.push_back({n,y});
	recur(y,ans);
}
int main()
{
	ll test;
	cin>>test;
	while(test--)
	{
		ll n;
		cin>>n;
		vector<pair<ll,ll>> ans;
		recur(n, ans);
		cout <<ans.size()<< endl;
		for(auto p : ans)
			cout << p.first << " " << p.second << '\n';
	}
}