#include <bits/stdc++.h>
using namespace std;
#define int long long int
// Function to find the sum of all the
// power of prime factors of N
int findSum(int n)
{
    /*int sum = 0;
    for(int i = 2; i <= N; i++)
        sum+=generatePrimeFactors(i);
    return sum;*/
    int ret=0;
    while (n%2 == 0)
    {
        ret++;
        n = n/2;
    }

    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            ret++;
            n = n/i;
        }
    }

    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        ret++;
    return ret;
}
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int32_t main()
{
    fast_cin();
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k,ans=0;
        cin>>a>>b>>k;
        if(k==1)
		{
			if(max(a,b)%min(a,b)==0&&a!=b)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			continue;
		}
        //int x=__gcd(a,b);
        ans+=findSum(a)+findSum(b);
        if(ans>=k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}