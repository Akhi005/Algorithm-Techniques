#include<bits/stdc++.h> // O(log n)
using namespace std;
#define ll long long

ll bin_exp(ll a, ll b, ll m)
{
    if(b==1)
        return a;
    ll res= bin_exp(a,b/2,m);
    if(b%2==1)
        return (res*res*a)%m;
    else
        return (res*res)%m;
}
ll binpow(ll a, ll b, ll m)
{
    ll res=1;
    while(b>0)
    {
        if(b&1) //if last digit is 1
        {
            res=res*a;
            res=res%m;
        }
        a*=a;
        a%=m;
        b>>=1;/* if b=1101 ->  after right shift b=110 */
    }
    return res;
}

int main()
{
    ll n,t,a,b,m,i=1,j;
    cin>>a>>b>>m;
    cout<<bin_exp(a,b,m)<<endl;
    cout<<binpow(a,b,m)<<endl;
}
