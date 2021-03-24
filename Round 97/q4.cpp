#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int j=0;j<T;j++)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        	cin>>v[i];
        vector<int> ans(n,0);
        queue<int> q;
        queue<int> tr;
        int s=1;
        q.push(0);
        tr.push(0);
        int b=1;
        while(q.size()!=n)
        {
            int k=tr.front();
            while(s<n)
            {
                if(v[s]<v[s+1])
                {
                    ans[s]=ans[k]+1;
                    q.push(s);
                    tr.push(s);
                    s++;
                    if(s==n-1)
                    {
                        q.push(s);
                        ans[s]=ans[k]+1;
                        break;
                    }
                }
                else
                {
                    ans[s]=ans[k]+1;
                    q.push(s);
                    tr.push(s);
                    s++;
                    break;
                }
            }
            tr.pop();
        }
        sort(ans.begin(),ans.end(),greater<int>());
        cout<<ans[0]<<endl;
    }
    return 0;
}