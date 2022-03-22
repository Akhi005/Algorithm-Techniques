#include<bits/stdc++.h>

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
ll dp[100][100];
ll lcs(string &s1 , string &s2, ll n, ll m)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n]==s2[m]) return dp[n][m] = 1 + lcs(s1,s2,n-1,m-1);
    else  return dp[n][m]=max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
}
int main()
{
    init();
    string s1,s2;
    cin>>s1>>s2;
    ll n,m,i,j;
    n=s1.size();
    m=s2.size();
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    lcs(s1,s2,n,m);
    cout<<dp[n][m]<<endl;
}