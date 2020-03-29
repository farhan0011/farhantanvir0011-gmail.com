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
       int d = max(a,max(b,c));
       if(a > b && a > c)
       {
           dp[i][j] = a;
           dr[i][j] = 1;
       }
       else if(b > a && b > c)
       {
           dp[i][j] = b;
           dr[i][j] = 2;
       }
       else if (c > a && c > b)
       {
           dp[i][j] = c;
           dr[i][j] = 3;
       }
    return dp[i][j];
}
void g(int i,int j)
{
    if(i == A.size() || j == B.size())
        return ;
    int d = dr[i][j];
    if(d == 1)
    {
        cout<<A[i];
        g(i+1, j+1);
    }
    else if(d == 2)
    {
        g(i+1,j);
    }
    else if(d == 3)
        g(i,j+1);
}
int main()
{
    //int n;
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        memset(dp, -1 , sizeof dp);
        memset(dr, -1 , sizeof dr);
    cin>>A>>B;
    int ans =f(0,0);
    cout<<ans<<endl;
    if(ans>0)
    {
        cout<<"Case "<<t<<": ";
        g(0,0);
          cout<<endl;
    }
    else
        cout<<"Case "<<t<<": :("<<endl;
    }
}

