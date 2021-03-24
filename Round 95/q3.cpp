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
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ans.push_back(x);
        }
        int dir=0;
        int j=0;
        int s=0;
        while(j<n)
        {
            if(dir==1)
            {
                if(ans[j]==1)
                {
                    if(ans[j+1]==1)
                        j=j+2;
                    else
                        j++;
                }
                dir=1-dir;
            }
            else
            {
                if(ans[j]==1)
                {
                    if(ans[j+1]==0)
                    {
                        j=j+2;
                        s++;
                    }
                    else
                    {
                        j=j+1;
                        s++;
                    }
                }
                else
                {
                    if(ans[j+1]==0)
                    {
                        j=j+2;
                    }
                    else
                    {
                        j++;
                    }
                }
                dir=1-dir;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}