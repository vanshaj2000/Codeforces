#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2==1)
        {
            int sum=((n-1)/2)*3;
            vector<int> req(n,sum);
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(req[i]>0)
                    {
                        cout<<"1 ";
                        req[i]-=3;
                    }
                    else
                    {
                        cout<<"-1 ";
                        req[j]-=3;
                    }
                }
            }
        }
        else
        {
            int pf=1;
            for(int i=0;i<n-1;i++)
            {
                int req=n-1-i;
                if(i%2==0)
                    cout<<"0 ",req--;
                int tf=pf;
                for(int j=0;j<req;j++)
                {
                    cout<<tf<<" ";
                    tf=(tf)*(-1);
                }
                pf=(pf)*(-1);
            }
        }
        cout<<endl;
    }
    return 0;
}