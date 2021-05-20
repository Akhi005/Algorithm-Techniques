#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll weight[10000], price[10000];
ll knapsack(ll W, ll weight[], ll price[], ll n)
{
    if(n==0 || W==0)
        return 0;
    if(weight[n-1] > W)
        return knapsack(W, weight, price,n-1);
    else
        return  max( price[n-1] + knapsack( W-weight[n-1], weight, price,n-1) , knapsack( W, weight, price, n-1));
}

int main()
{
    ll t,i,j,k,l,m,n,w,x,y,z,W,ans;
    cin>>n>>W;
    for(i=0 ; i<n; i++)
        cin>>weight[i]>>price[i];
    ans = knapsack(W, weight, price, n);
    cout<<ans<<endl;
    return 0;
}
