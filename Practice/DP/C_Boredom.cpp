#include <bits/stdc++.h> 
using namespace std;
#define int long long int
int32_t main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    vector<pair<int,int>> fin;
    for(int i=0;i<v.size();i++)
    {
        if(fin.size()==0)
            fin.push_back({v[i],1});
        else
        {
            if(v[i]==fin.back().first)
                fin[fin.size()-1].second++;
            else
                fin.push_back({v[i],1});
        }
    }
    fin.insert(fin.begin(),{0,1});
    int av=0,us=0;
    for(int i=1;i<fin.size();i++)
    {
        int temp=us;
        if(fin[i].first==fin[i-1].first+1)
            us=max(av+fin[i].first*fin[i].second,us);
        else
            us=fin[i].first*fin[i].second+max(us,av);
        av=max(temp,av);
    }
    cout<<max(av,us);
    return 0;
}