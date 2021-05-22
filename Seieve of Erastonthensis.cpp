#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool prime[1000000000];
void seive(int n) // using bool
{
    int i,j;
    for(i=0; i<n; i++)
        prime[i]=true;
    prime[0]=false, prime[1]=false;
    for(i=2; i<n; i++)
    {
        if(prime[i])
        {
            for(j=i*i; j<n; j+=i)
                prime[j]=false;
        }
    }
    for(i=0; i<=n; i++)
    {
        if(prime[i]==true)
            cout<<i<<' ';
    }
}
void seive_of(int n) // using bitset
{
    vector<int>prm;
    bitset<100007>bt;
    bt.set();  // 1
    bt[0]=bt[1]=0;
    int i,j;
    prm.push_back(2);
    for(i=3; i<n; i+=2)
    {
        if(bt[i])
        {
            for(j=i*i; j<n; j+=i)
            {
                bt[j]=0;
            }
            prm.push_back(i);
        }
    }
    for(i=0; i<n; i++)
        cout<<prm[i]<<' ';
}
int main()
{
    int n,i;
    cin>>n;
    seive(n);
    for(i=0; i<=n; i++)
    {
        if(prime[i]==true)
            cout<<i<<' ';
    }
    return 0;
}
