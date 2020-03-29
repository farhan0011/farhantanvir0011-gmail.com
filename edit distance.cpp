#include<bits/stdc++.h>
using namespace std;
string A,B;
int dp[1010][1010];
int f(int i,int j)
{
    if(j == B.size())///full milano hoi gese r milanur kisu nai
        return 0;
    if(i == A.size())///B er cur ind theke update kore milai dilam
        return (B.size() - j ) ;
    if(A[i] == B[j])
        return dp[i][j] = f(i+1,j+1);
    int a,b,c;
    a = 1 + f(i,j + 1);///new value insert kore milai dilam tai B er ind ek baralam
    b = 1 + f(i+1,j);///erase korlam,tar mane A er ind ek baralam
    c = 1 + f(i+1,j+1);///update kore milai dilam tai dui jn er ind ek kore baralam
    return dp[i][j] = min(a,min(b,c));
}
int main()
{
    cin>>A>>B;
    cout<<f(0,0)<<endl;
}
