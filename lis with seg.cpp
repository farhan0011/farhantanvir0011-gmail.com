#include<bits/stdc++.h>
using namespace std;
#define MX 100005
int tree[MX];
int A[100005];
int n;
void update(int node,int st,int ed,int ind,int v)
{
    if(st>ind || ed<ind)
        return ;
    if(st == ind && ed == ind)
    {
        tree[node] = v;
        return;
    }
    int lf = 2 * node;
    int rg = 1 + lf;
    int md = (st + ed)/2;
    update(lf,st,md,ind,v);
    update(rg,md+1,ed,ind,v);
    tree[node] = max(tree[lf],tree[rg]);
    return ;
}
int query(int node,int st,int ed,int i,int j)
{
    if(st>j ||ed<i)
        return 0;
    if(st>=i && ed<=j)
        return tree[node];
    int md = (st+ed)/2;
    int lf = 2 * node;
    int rg = 1 + lf;
    int a = query(lf,st,md,i,j);
    int b = query(rg,md+1,ed,i,j);
    return tree[node] = max(a,b);
}
int f()
{
    memset(tree,0,sizeof tree);
    int ans = 1;
    for(int in = 0; in<n; in++)
    {
        int mx = 1 + query(0,0,MX,0,A[in] - 1);
        ans = max(ans,mx);
        update(0,0,MX,A[in],mx);
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>A[i];
    cout<<f()<<endl;
}
