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
        vector<int> src(102,0);
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            src[x]++;
        }
        int num=0;
        while(src[num]>=2)
        {
            num++;
        }
        if(src[num]==0)
            cout<<2*num<<endl;
        else
        {
            int sum=num;
            while(src[num]>0)
            {
                num++;
            }
            sum=sum+num;
            cout<<sum<<endl;
        }
    }
    return 0;
}