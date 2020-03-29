#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int arr[1010];
int n,maxInA;
int f(int in,int last)
{
    for(last = 0;last<=maxInA;last++)
   {
       dp[n][last] = 0;
   }
   for( in = n-1;in>=0;in--)
   {
       for( last = 0;last<=maxInA;last++)
       {
           int a = 0,b=0;
           b = dp[in+1][last];
           if(last < arr[in])
            a =  1 + dp[in+1][arr[in]];
           dp[in][last] = max(a,b);
       }
   }
   return dp[0][0];
}
int main()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
       if(arr[i]>maxInA)
        maxInA = arr[i];
   }
   memset(dp , -1 , sizeof dp);
   cout<<f(0,0)<<endl;
   for(int i=0;i<=n;i++)
   {
       for(int last = 0;last<=maxInA;last++)
        cout<<dp[i][last]<<" ";
       cout<<endl;
   }
}
