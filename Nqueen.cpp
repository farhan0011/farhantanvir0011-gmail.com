#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int coltaken[20],d1taken[40],d2taken[40];
int board[20][20];
bool f(int r)
{
    if(r == n)
        return true;
    for(int c=0; c<n; c++)
    {
        if(coltaken[c])
            continue;
        int d1 = r+c;
        int d2 = r+n-c-1;
        if(d1taken[d1])
            continue;
        if(d2taken[d2])
            continue;
        coltaken[c] = 1;
        d1taken[d1] = 1;
        d2taken[d2] = 1;
        board[r][c] = 1;
        if(f(r+1))
           cnt++;
        coltaken[c] = 0;
        d1taken[d1] = 0;
        d2taken[d2] = 0;
        board[r][c] = 0;
    }
    return false;
}
int main()
{
    cin>>n;
    f(0);
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0; j<n; j++)
//            cout<<board[i][j]<<" ";
//        cout<<endl;
//    }
    cout<<cnt<<endl;
}
