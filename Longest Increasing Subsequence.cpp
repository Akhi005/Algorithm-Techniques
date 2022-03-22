#include<bits/stdc++.h> //O(n^2)

using namespace std;
#define ll  long long
#define lim 10009
void init()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/Ppt/input.txt", "r", stdin);
    freopen("E:/Ppt/outpuut.txt", "w", stdout);
    #endif // ONLINE_JUDGE
  
}
ll dp[100];
ll lis(ll arr[] , ll n)
{
    if(dp[n]!=-1) return dp[n];
    dp[n]=1;
    for(int i=0;i<n;i++)
    {
        if(arr[n]>arr[i])
           dp[n]=max(dp[n], 1+lis(arr,i));
    }
    return dp[n];
}
int main()
{
    init();
    ll n,i,j;
    cin>>n;
    ll arr[n+2];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<=n;i++)
    {
         dp[i]=-1;
    }
    lis(arr,n-1);
    cout<<dp[n-1]<<endl;
}