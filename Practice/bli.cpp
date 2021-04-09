#include <bits/stdc++.h>   
using namespace std;

int recurM(unordered_map<int,int> &ump,int mask,vector<int> &v,unordered_map<int,int> &ump2)
{
    if(ump2[mask]>0)
        return ump[mask];
    int curr=0;
    int flag=0;
    for(int i=0;i<v.size();i++)
    {
        if((mask&(1<<i))!=0)
        {
            if(!flag)
                curr+=v[i];
            else
                curr-=v[i];
            flag=1-flag;
        }
    }
    ump[mask]=curr;
    //cout<<curr<<endl;
    for(int i=0;i<v.size();i++)
    {
        if((mask&(1<<i))==0)
            ump[mask]=max(ump[mask],recurM(ump,mask|1<<i,v,ump2));
    }
    ump2[mask]=1;
    return ump[mask];
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    unordered_map<int,int> ump;
    unordered_map<int,int> ump2;
    int ans=recurM(ump,0,v,ump2);
    cout<<ans;
    return 0;
}