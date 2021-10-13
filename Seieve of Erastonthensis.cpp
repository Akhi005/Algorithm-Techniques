#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[1000000000];
vector<ll>prm;
ll i,j;
bitset<1000000007>mark;
void seive() // using bool
{
    memset(vis,false,sizeof(vis));
    prm.push_back(2);
    for(i=3; i<=10000000; i+=2)
    {
        if(vis[i]==false)
        {
            for(j=i*i; j<=1000000; j+=2*i)
                vis[j]=true;
            prm.push_back(i);
        }
    }
}
void seive_of() // using bitset
{
    int i,j;
    prm.push_back(2);
    for(i=3; i<100000000; i+=2)
    {
        if(mark[i]==0)
        {
            if(i*1LL*i>=100000000) continue;
            for(j=i*i; j<100000000; j+=2*i)
                mark[j]=1;

            prm.push_back(i);
        }
    }
}
int main()
{
    int n,i;
    cin>>n;
    seive_of();
    for(i=0; i<=n; i++)
    {
            cout<<prm[i]<<' ';
    }
    return 0;
}
