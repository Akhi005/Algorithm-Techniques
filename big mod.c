#include<stdio.h>
#define ll long long
ll bigMod(ll a, ll b,ll mod)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1; // b/=2;
    }
    return res;
}
int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    printf("%d\n",bigMod(n,k,m));
    return 0;
}
