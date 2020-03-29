#include<bits/stdc++.h>
using namespace  std;
int arr[1010][1010];
int n,m;
int dp[1010][1010];
int f(int r,int c)
{
    if(r == n-1 && c == m-1)
        return arr[r][c];
    if(r>=n || c>=m)
        return 0;
    if(r<0 || c<0)
        return 0;
    if(dp[r][c]!= -1)
        return dp[r][c];
    int a = arr[r][c] + f(r+1,c);
    int b = arr[r][c] + f(r+1,c-1);
    int d = arr[r][c] + f(r+1,c+1);
    return  dp[r][c] = max(a,max(b,d));
}
int main()
{
    memset(dp , -1 , sizeof dp);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    cout<<f(0,0)<<endl;
}
