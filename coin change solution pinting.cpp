#include<bits/stdc++.h>
using namespace std;
int n,val;
int coin[1010];
int dp[1010][1010];
int dr[1010][1010];
int f(int in,int rem)
{
    if(rem < 0)
        return INT_MIN;
    if(in == n)
    {
        if(rem == 0)
            return 1;
        else return 0;
    }
    if(dp[in][rem] != -1)
        return dp[in][rem];
    int a = f(in + 1,rem - coin[in]);
    int b = f(in +1,rem);
    if(a>=b)
    {
        dp[in][rem] = a;
        dr[in][rem] = 1;
    }
    else
    {
        dp[in][rem] = b;
        dr[in][rem] = 0;
    }
    return dp[in][rem];
}
int main()
{
    memset(dp,-1,sizeof dp);
    memset(dr,-1,sizeof dr);
    cin>>n>>val;
    for(int i=0;i<n;i++)
        cin>>coin[i];
    cout<<f(0,val)<<endl;
}
