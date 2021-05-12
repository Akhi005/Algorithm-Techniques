#include<bits/stdc++.h>
using namespace std;
#define ll long long
int b[500001],i,j,x,y,z,q,n,k,maxx=0,maxxindex=0,t;
int main()
{
    cin>>n>>k>>q;
    memset(b,0,sizeof(b));
    for(i=1; i<=n; i++)
    {
        cin>>x>>y;
        b[x]++;
        b[y+1]--;
    }
    for(i=1; i<500001; i++)
    {
        b[i]+=b[i-1];
    }
    for(i=0; i<500001; i++)
    {
        if(b[i]>=k)
            b[i]=1;
        else
            b[i]=0;
    }
    for(i=1; i<500001; i++)
        b[i]+=b[i-1];

    while(q--)
    {
        cin>>x>>y;
        cout<<b[y]-b[x-1]<<endl;
    }
    return 0;
}
