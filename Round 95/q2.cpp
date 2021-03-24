#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        vector<int> ans1(n,0);
        vector<int> ans2(n,0);
        vector<int> fr;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ans1[i]=x;
        }
        for(int i=0;i<n;i++)
        {
            int y;
            cin>>y;
            ans2[i]=y;
            if(y==0)
                fr.push_back(ans1[i]);
        }
        sort(fr.begin(),fr.end(),greater<int>());
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(ans2[i]==0)
            {
                ans1[i]=fr[j];
                j++;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans1[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}