#include<bits/stdc++.h>
using namespace std;
#define ll long long
/* Ordered_set

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define orderedSet tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    orderedSet st;
    st.insert(6);
    st.insert(2);
    st.insert(4);
    st.insert(12);
    st.insert(9);
    cout<< *(st.find_by_order(3))<<endl;
    cout<< st.order_of_key(9) <<endl;
} */
/* mpp.max_load_factor(0.25); mpp.reserve(1024); */
/* cout << fixed << setprecision(12);*/
/*ll arr[1000000];
ll to_bin(string &s)
{
    int i=0,rem=0;
    reverse(s.begin(),s.end());
    while(s[i]!='\0')
    {
        rem=rem+(pow(2,i)*(s[i]-'0'));
        i++;
    }
    return rem;
}
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

#define lim 5001
#define len 1050
int fbn[lim][len];
void fibonacci()
{
    int i,j,k,sum;
    fbn[0][0]=0;
    fbn[1][0]=1;
    fbn[2][0]=1;
    for(i=3; i<lim; i++)
    {
        for(j=0; j<len; j++)
        {
            fbn[i][j]+=fbn[i-2][j]+fbn[i-1][j];
            if(fbn[i][j]>=10)
            {
                fbn[i][j+1]+=fbn[i][j]/10;
                fbn[i][j]%=10;
            }
        }
    }
}
fibonacci();
    int n,i,j,k,lenth;
    while( scanf("%d",&n ) == 1 )
    {
        for(i=len-1; i>0; i--)
        {
            if(fbn[n][i]!=0)
                break;
        }
        for( ; i>=0 ; i-- )
            printf("%d",fbn[n][i]);
        printf("\n");
    }*/
ll fib[100];
void fibonacci()
{
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3 ; i <100 ; i++)
        fib[i] = fib[i-1] + fib[i-2];
}

int main()
{
    fibonacci();
    int tc,i,j,k;
    cin >> tc;
    map<ll,string>mp;
    while(tc--)
    {
        int n ;
        cin >> n;
        ll ar[n+10];
        for(int i = 0 ; i < n ; i++)
            cin >> ar[i];

        getchar();
        string str;
        getline(cin, str);
        int len = str.size();

        for(int i = 0, j = 0;  j<len && i < n  ; j++)
        {
            if(str[j] >= 'A' && str[j] <= 'Z')
            {
                mp[ar[i]]=str[j];
                i++;
            }
        }
        map<ll,string >:: iterator it;
        j=1;
        for( it = mp.begin(); it != mp.end() ; )
        {
            if(it->first == fib[j])
            {
                cout << it->second ;
                it++;
            }
            else
            {
                cout <<' ';
            }
            j++;
        }
        cout << "\n";
        mp.clear();
    }

    return 0;
}
