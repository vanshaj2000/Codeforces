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
        long long int x,y,k;
        cin>>x>>y>>k;
        long long int a=((y*k)+k-1)/(x-1);
        a=a+k;
        if(((y*k)+k-1)%(x-1)!=0)
            a++;
        cout<<a<<endl;
    }
    return 0;
}