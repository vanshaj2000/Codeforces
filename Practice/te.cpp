#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
vector<vector<int>> ans;
set<vector<int>> s;
vector<int> v;
void solve(vector<int> &A ,int B ,int ind)
{
    if(B==0)
    {
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
        s.insert(v);
        return;
    }
    if(B<0 || ind>=A.size())
    return;
    
    v.push_back(A[ind]);
    solve(A,B-A[ind],ind+1);
    v.pop_back();
    solve(A,B,ind+1);
}
int32_t main()
{
    vector<int> A={9,1,2,7,6,1,5};
    int N=7,B=8;
    sort(A.begin(),A.end());
    solve(A,B,0);
    for(vector<int> k:s)
    ans.push_back(k);
    cout<<ans.size();
}