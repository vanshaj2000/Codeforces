#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int a[N],b[N],A[N],B[N];
int main()
{
	int n,m,x,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i]+=a[i-1];
		A[i]=a[i];
		for(int j=1;j<i;j++) A[i-j]=min(A[i-j],a[i]-a[j]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",b+i);
		b[i]+=b[i-1];
		B[i]=b[i];
		for(int j=1;j<i;j++) B[i-j]=min(B[i-j],b[i]-b[j]);
	}
	cin>>x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(A[i]*1LL*B[j]<=x) ans=max(ans,i*j);
		}
	}
	cout<<ans;	
}
