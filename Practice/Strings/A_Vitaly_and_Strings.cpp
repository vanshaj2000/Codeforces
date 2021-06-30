#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define MOD 1000000007
int32_t main()
{
    fast_cin();
    string s1,s2;
    cin>>s1>>s2;
    int f=0,s;
    string ans="No such string";
    for(int i=0;i<s1.size();i++)
    {
        if(s2[i]-s1[i]==1)
            f++,s=i;
        if(abs(s2[i]-s1[i])>1)
        {
            if(s1[i]>s2[i])
            {
                if(s1[i]!='z')
                    ans=s1,ans[i]=s1[i]+1;
                else
                {
                    if(s2[i]!='a')
                        ans=s2,ans[i]=s2[i]+1;
                    else
                    {
                        if(f<2)
                        {
                            for(int j=i+1;j<s2.size();j++)
                            {
                                if(s1[j]!='z')
                                {
                                    ans=s1,ans[j]=s1[j]+1;
                                    break;
                                }
                                if(s2[j]!='a')
                                {
                                    ans=s2,ans[j]=s2[j]-1;
                                    break;
                                }
                            }
                            break;
                        }
                        else
                            ans=s2,ans[s]=s1[s];
                    }
                }
            }
            else
            {
                ans=s1;
                ans[i]=s1[i]+1;
            }
            break;
        }
    }
    string tt1,tt2;
    for(int i=0;i<s1.size();i++)
    {
        if(s2[i]-s1[i]==1)
        {
            int n=s1.size();
            string k(n-i-1,'a'),k2(n-i-1,'z');
            //cout<<k<<" "<<k2<<endl;
            tt1=((s2.substr(0,i+1))+k);
            tt2=(s1.substr(0,i+1))+k2;
            if(tt1>s1&&tt1<s2)
                ans=tt1;
            else if(tt2>s1&&tt2<s2)
                ans=tt2;
        }
    }
    cout<<ans;
}