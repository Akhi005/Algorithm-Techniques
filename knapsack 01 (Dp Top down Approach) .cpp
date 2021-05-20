#include <bits/stdc++.h> // O(n*W)
using namespace std;
#define ll long long
ll weight[10000], price[10000]  ,K[1000][1000];
ll knapsack(ll W, ll weight[], ll price[], ll n)
{
    ll i,w;
    for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				K[i][w]=0;
			else if(weight[i-1] <= w)
				K[i][w] = max( K[i-1][w] , K[i-1][w-weight[i-1]]+price[i-1] ) ;
		   else K[i][w]=K[i-1][w];
		}
	}
	return K[n][W];
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
