#include<bits/stdc++.h>
using namespace std;
int P[1010];
int W[1010];
int dp[1010][1010];
int dr[1010][1010];
int n;
int f(int in ,int rem)
{
    if(rem < 0)
        return INT_MIN;
    if(in == n)
        return 0;
    if(dp[in][rem] != -1)
        return dp[in][rem];
    int a = P[in] + f(in + 1,rem - W[in]);
    int b = f(in + 1,rem);
    if(a >= b)
    {
        dp[in][rem] = a;
        dr[in][rem] = 1;
    }
    else{
        dp[in][rem] = b;
        dr[in][rem] = 0;
    }
    return dp[in][rem];
}
void g(int in,int rem)
{
    if(rem < 0)
        return ;
    if(in == n)
        return ;
    if(dr[in][rem] == 1)
    {
        cout<<P[in]<<endl;
        f(in + 1,rem - W[in]);
    }
    else if(dr[in][rem] == 0)
    {
        f(in + 1,rem);
    }
}
int main()
{
    memset(dp, -1 ,sizeof dp);
    memset(dr, -1 ,sizeof dr);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>P[i]>>W[i];
        int cap;
    cin>>cap;
    cout<<f(0,cap)<<endl;
    g(0,cap);
}
