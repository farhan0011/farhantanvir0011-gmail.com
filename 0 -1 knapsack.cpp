#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
int V[LIM],W[LIM];
int dp[1010][1010];
int dr[1010][1010];
///recursive sol
/*int f(int in,int rem,int n)
{
    if(rem<0)
        return INT_MIN;
    if(in==n)
        return 0;
    int a=V[in]+f(in+1,rem-W[in],n);
    int b=f(in+1,rem,n);
    return max(a,b);
}*/
int f(int in,int rem,int n)
{
    if(rem<0)
        return INT_MIN;
    if(in == n)
        return 0;
        if(dr[in][rem]!=0)
            {
                return dp[in][rem];
            }
    int a=V[in]+f(in+1,rem-W[in],n);
    int b = f(in+1,rem,n);
    dr[in][rem] = 1;
    return dp[in][rem]= max(a,b);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,cap;
        memset(V,0,sizeof V);
        memset(W,0,sizeof W);
        cin>>n>>cap;
        for(int i=0;i<n;i++)
            cin>>W[i];
        for(int i=0;i<n;i++)
            cin>>V[i];
        memset(dr,0,sizeof dr);
        cout<<f(0,cap,n)<<endl;;
    }
}
