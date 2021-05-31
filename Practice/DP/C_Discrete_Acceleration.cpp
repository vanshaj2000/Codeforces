#include <bits/stdc++.h>  
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define double long double
int32_t main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,sp1=1,sp2=1;
        cin>>n>>l;
        int f1=0,f2=n-1;
        vector<double> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        double s=0,e=l,tot=0;
        while(e-s>0)
        {
            double t1=f1<n?v[f1]:1000000000,t2=f2>=0?v[f2]:-1000000000,t3=e-s;
            t1=t1-s,t2=e-t2;
            double tim1=t1/sp1,tim2=t2/sp2,tim3=(t3/(sp1+sp2));
            double tim=min(tim1,min(tim2,tim3));
            tot+=tim;
            s+=sp1*tim,e-=sp2*tim;
            if(tim==tim1)
                sp1++,f1++;
            if(tim==tim2)
                sp2++,f2--;
        }
        cout<<fixed<<setprecision(15)<<tot<<endl;
    }    
    return 0;
}