#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000][1000],r[1000000],c[1000000];
int main()
{
    ll n,m,t,i,j,k,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++){
				arr[i][j]=0;
			    r[j]=0;
			    c[i]=0;
			}
		}
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>a;
                c[a]=j;
            }
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                cin>>b;
                r[b]=j;
            }
        }
        for(i=1; i<=n*m; i++)
        {
            arr[r[i]][c[i]]=i;
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cout<<arr[i][j]<<' ';
            }
            cout<<endl;
        }
    }
}
