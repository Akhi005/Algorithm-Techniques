#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arr[10002],tree[50000];
int node,b,e,n,l,mid,i,j;
void built(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    built(left,b,mid);
    built(right,mid+1,e);
    tree[node]=tree[b]+tree[e];
}
int query(int node, int b,int e, int l, int r)
{
    if(l>e || r<b)
        return 0;
    if(b==e)
        return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    query(left,b,mid,l,r);
    query(right,mid+1,e,l,r);
    return  query(left,b,mid,l,r)+query(right,mid+1,e,l,r);
}
void update(int node, int b,int e,int pos,int value)
{
    if(pos<b || pos>e) return ;
    if(b==e){
        tree[node]=value;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,pos,value);
    update(right,mid+1,e,pos,value);
    tree[node]=tree[b]+tree[e];
}
int main()
{
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    built(1,0,n);
    cout<<query(1,0,n,3,7)<<endl;
    update(1,0,n,5,9);
    cout<<query(1,0,n,3,7)<<endl;
}
