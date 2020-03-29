#include<bits/stdc++.h>
using namespace std;
#define LIM 105
string A,B;
int n;
int dp[LIM][LIM];
int dr[LIM][LIM];
int f(int i,int j)
{
    if(i == A.size() || j == B.size())
        return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
    int a = 0,b = 0,c = 0 ;
    if(A[i] == B[j])
    {
        a = 1 + f(i+1,j+1);
    }
       b = f(i + 1,j);
       c = f(i,j+1);
    return dp[i][j] = max(a,max(b,c));
}
int main()
{
    //int n;
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        memset(dp, -1 , sizeof dp);
    cin>>A>>B;
    int ans =f(0,0);
    cout<<ans<<endl;
    }
}
