#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[505][1010];
ll f(int rem,int last)
{
    ///jodi bole exact n brick nite hbe tkhn base case hbe
     if(rem == 0) return 1;
       ll ans =0;
    if(dp[rem][last] != -1)
        return dp[rem][last];
    //int ans = 1;
    for(int cur = last + 1; cur <= rem; cur++)
        ans += f(rem - cur, cur);
    return dp[rem][last] = ans;
}
int main()
{
    ll n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<f(n,0)-1<<endl;
}
