#include<bits/stdc++.h>
using namespace std;

/* Policy base data structure  (PBDS) */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define apnt(arr, num) for(ll i = 0; i < num; i++) cout << arr[i] << (i + 1 < num ? ' ' : '\n');

/*** Define Values ***/
#define mx 200005
#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-7
#define size1 7500

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
///for Unordered map
/* mpp.max_load_factor(0.25); mpp.reserve(1024); */
#define min_heap  priority_queue <ll, vector<ll>, greater<ll> >
/* cout << fixed << setprecision(12);*/

/*** STLs ***/
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll, ll> > vpll;
#define mod 1000000007
inline ll MOD(ll a){return (a%mod + mod) %mod ;}
inline ll modAdd(ll a,ll b){return MOD( MOD(a) + MOD(b) ) ;}
inline ll modSub(ll a,ll b){return MOD( MOD(a) - MOD(b) ) ;}
inline ll modMul(ll a,ll b){return MOD( MOD(a) * MOD(b) ) ;}
inline bool cmp(pll a,pll b)
{
    if(a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff > b.ff;
}
/** Binary_string to decimal_number**/
ll binary_string_to_decimal(string &s)
{
    ll rem=0,i,l=s.size();
    for(i=0; i<l; i++)
        rem=rem*2+(s[i]-'0');
    return rem;
}

/*** BitWise Operations ***/
bool getBit (ll num, ll pos)
{
    return num & (1 << pos);    // get bit right -> left
}
/*ll setBit (ll num, ll pos)
{
    return num | (1 << pos);
}
ll chearBit (ll num, ll pos)
{
    ll mask = ~(1 << pos);
    return num & mask;
}
ll updateBit (ll num, ll pos, bool bit1or0)
{
    ll value = bit1or0 ? 1 : 0;
    ll mask = ~(1 << pos);
    return (num & mask) | (value << pos);
}
*/
/*** Grids ***/
int drx[8] = {-2,-2,-1,-1,1,1,2,2};
int dcy[8] = {-1,1,-2,2,-2,2,-1,1};
int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, -1, 0, 1 };

/*** Functions ***/
ll BigMod(ll base, ll pow, ll modvalue)
{
    if (pow == 0)
        return 1;
    ll ans = BigMod(base, pow / 2, modvalue);
    ll total = ((ans % modvalue) * (ans % modvalue)) % modvalue;
    if(pow % 2 == 0)
        return total;
    else
    {
        return (total * (base % modvalue) ) % modvalue;
    }
}
ll InverseMod(ll base, ll pow)
{
    if(pow == 0)
        return 1;
    ll ans = InverseMod(base, pow / 2);
    ans = (ans * ans) % mod;
    if(pow & 1)
    {
        return (ans * base) % mod;
    }
    else
    {
        return ans;
    }
}
/*  SET */
//set <int, greater <int> > s1;
//set <int> s2(s1.begin(), s1.end());
//    cout << *s2.lower_bound(40) << endl;
/*  // remove all elements up to 30 in s2
  s2.erase(s2.begin(), s2.find(30));*/

/*   // remove element with value 50 in s2
num = s2.erase (50);*/
bool checkprime(ll num)
{
    if(num < 2)
        return false;
    else if(!(num&1)) return false;
    for(ll i = 3; i * i <= num; i+=2)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}
std::string tobinary(ll n)
{
    std::string r;
    while(n!=0)
    {
        r=(n%2==0 ? "0":"1")+r;
        n/=2;
    }
    return r;
}
ll bin_expo(ll x,ll n) // native
{
    ll res=1;
    while(n)
    {
        if(n%2)
            res*=x , n--;
        else
            x*=x , n/=2;
    }
    return res;
}
ll mod_expo(ll x,ll n,ll p)
{
    ll res=1;
    while(n)
    {
        if(n%2)
            res=(res*x)%p , n--;
        else
            x=(x*x)%p , n/=2;
    }
    return res;
}
ll bi_ex(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n%2==1) res=((res%mod)*(x%mod))%mod;
        x=((x%mod)*(x%mod))%mod;
        n>>=1;  //  n/2
    }
    return res%mod;
}
 ll power(ll x, ll n) // x^n // native
{
    if(n==0) return 1;
    if(!(n&1)){ ll y =  power(x , n/2) ;return y*y;}
    else return  x*power(x , n-1);
}
ll pow(ll x, ll n) // x^n
{
    if(n==0) return 1;
    if(!(n&1)) return pow(x*x , n>>1); // n>>1 ==  n/2
    else return  x*pow(x*x , (n-1)>>1);
}

int main()
{
   // clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    FastIO;
 //   cout<<getBit(10,2)<<endl;
  //  cout<<BigMod(10,3,30 <<endl ;
  // cout<<tobinary(16)<< endl ;
//  cout<<power(5,3);
 string s = "2050";
 cout<<stol(s,nullptr,10)<<endl;
 cout<< stol(s,nullptr,2);


   // printf("\nRun Time -> %.10fs\n", (double)(clock()-tStart) / CLOCKS_PER_SEC);
}
