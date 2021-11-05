#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int weight[1000],price[10000];
int dp[100][100];
int knap(int n,int W)
{
    if(n==0 || W==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(weight[n]>W) return dp[n][W]= knap(n-1,W);
    return dp[n][W]= max((price[n]+knap(n-1,W-weight[n])), knap(n-1,W));
}
int main()
{
   int n,i,j,k,W;
   cin>>n>>W;
   for(i=1;i<=n;i++)
    cin>>weight[i]>>price[i];
    memset(dp,-1,sizeof dp);
   k=knap(n,W);
   cout<<k<<endl;
    return 0;
}
