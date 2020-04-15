#include<bits/stdc++.h>
using namespace std;
int G[20][20];
#define MAX 1000006
int target;
int n,m,w;
int dp[16][(1<<16)+100];
int setbit(int mask,int p)
{
    return mask | (1 << p);
}
int checkbit(int mask,int p)
{
    return mask & (1<<p);
}
int toggle(int mask,int p)
{
    return mask ^ (1<<p);
}
int f(int u,int mask)
{
    if(mask == target)
        return G[u][0];
    if(dp[u][mask] != -1)
        return dp[u][mask];
    int ans = MAX;
    for(int i=0; i<n; i++)
    {
        int cost = G[u][i];
        if(checkbit(mask,i))
            continue;
        int temp = cost + f(i,setbit(mask,i));
        if(temp<ans)
            ans = temp;
    }
    return dp[u][mask] = ans;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u][v] = G[v][u] = w;
    }
    //vis[1] = 1;
    memset(dp,-1,sizeof dp);
    target = (1<<n)-1;
    cout<<f(0,1)<<endl;
}
/**
4 6
0 1 10
0 2 15
0 3 20
1 2 35
1 3 25
2 3 30
*/


