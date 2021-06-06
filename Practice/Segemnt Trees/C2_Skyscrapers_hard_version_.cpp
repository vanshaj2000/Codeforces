#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
int getMin(vector<int> &a,vector<int> &t,int ss,int se,int qs,int qe,int index) 
{
    if(qs<=ss&&qe>=se) 
        return t[index];
    if(se<qs||ss>qe) 
        return INT_MAX;
    int mid=ss+(se-ss)/2; 
    int x1=getMin(a,t,ss,mid,qs,qe,2*index+1),x2=getMin(a,t,mid+1,se,qs,qe,2*index+2);
    if(a[x1]<=a[x2])
        return x1;
    else
        return x2;
    return -1;
}
vector<int> ans;
int sum;
int conTree(vector<int> &a,int ss,int se,vector<int> &t,int si)
{
    if(ss==se)
    {
        t[si]=ss;
        return ss;
    }
    int mid=ss+(se-ss)/2;
    int x1=conTree(a,ss,mid,t,2*si+1);
    int x2=conTree(a,mid+1,se,t,2*si+2);
    if(a[x1]<=a[x2])
        t[si]=x1;
    else
        t[si]=x2;
    return t[si];
}
int func(vector<int> &a,int s,int e,vector<int> &t,int n)
{
    //cout<<s<<" "<<e<<endl;
    if(s>e)
        return INT_MIN;
    if(s<0||e>=n||e<0||s>=n)
        return INT_MIN;
    if(s==e)
    {
        ans[s]=a[s];
        return a[s];
    }
    int ind=getMin(a,t,0,n-1,s,e,0);
    //cout<<s<<" "<<e<<" "<<ind<<endl;
    int suml=func(a,s,ind-1,t,n)+((e-ind+1)*a[ind]);
    int sumr=func(a,ind+1,e,t,n)+((ind-s+1)*a[ind]);
    if(suml>=sumr)
    {
        for(int i=ind;i<=e;i++)
            ans[i]=a[ind];
        return suml;  
    }
    else
    {
        for(int i=s;i<=ind;i++)
            ans[i]=a[ind];
        return sumr;
    }
    return -1;
}
int32_t main()
{
    fast_cin();
    ans.clear();
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    ans=a;
    vector<int> t(4*n);
    conTree(a,0,n-1,t,0);
    int x=func(a,0,n-1,t,n);
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}