#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 1000000007;
double eps = 1e-12;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct node
{
    int val;
    struct node *left;
    struct node *right;
    node(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};
struct node* solve(int s,int e,vector<int> &v)
{
    if(s==e)
        return new node(v[s]);
    if(e<s)
        return NULL;
    int m=*max_element(v.begin()+s,v.begin()+e+1);
    for(int i=s;i<=e;i++)
    {
        if(v[i]==m)
        {
            struct node* temp=new node(m);
            temp->left=solve(s,i-1,v);
            temp->right=solve(i+1,e,v);
            return temp;
        }
    }
    return NULL;
}
void trans(struct node* n,vector<int> &ans,int h)
{
    ans[(n->val)]=h;
    //cout<<n->val<<endl;
    if(n->left!=NULL)
        trans(n->left,ans,h+1);
    if(n->right!=NULL)
        trans(n->right,ans,h+1);
}
int main()
{
    fast_cin();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        struct node* root=solve(0,n-1,v);
        vector<int> ans(n+1);
        trans(root,ans,0);
        for(int i=0;i<n;i++)
            cout<<ans[v[i]]<<" ";
        cout<<endl;
    }
    return 0;
}