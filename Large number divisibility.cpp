#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[20000],n,i,l,j;  int p[200000];
/// a= -7678123668327637674887634  b = 101
int main()
{
    ll t,n,i,j,k;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s>>n;
       if(s[0]=='-') j=1;
       else j=0;
       int b=0;
       if(n<0) n=n*(-1);
       for(k=j;k<s.size();k++)
       {
           b=(s[k]-'0')+b*10;
           b=b%n;
       }
      if(b) cout<<"not divisible\n";
      else cout<<"divisible\n";
    }
}
