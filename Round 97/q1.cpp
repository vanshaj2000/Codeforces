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
        float l,r;
        cin>>l>>r;
        if(l>=(r+1)/2)
        	cout<<"YES"<<endl;
        else
        	cout<<"NO"<<endl;
    }
    return 0;
}