#include<bits/stdc++.h>
using namespace std;
vector<int>G[12];
int n,m;
int target;
//int dp[16][(1<<16)+100];
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
bool f(int u,int vismask)
{
/**
  01111
& 10000
--------
  00000
*/
    if(vismask == target)
        {
            //cout<<"vismask = "<<vismask<<" target = "<<target<<endl;
            return true;
        }
        //if(dp[u][vismask]!=-1)
            //return dp[u][vismask];
    for(int i=0; i<G[u].size(); i++)
    {
        //cout<<"YES"<<endl;
        int v = G[u][i];
        if(checkbit(vismask,v))
            continue;
            //getchar();
        //cout<<"vismask = "<<vismask<<" "<<setbit(vismask,v)<<endl;
        if(f(v,setbit(vismask,v)))
            //return dp[u][vismask] = true;
            return true;
    }
    //return dp[u][vismask] =  false;
    return false;
}
int main()
{
    cin>>n>>m;
    target = (1<<n)-1;
    //cout<<target<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    //
    //memset(dp , -1, sizeof dp);
     for(int i=0; i<n; i++)
     {
         ///vis[u] = 1;
         cout<<setbit(0,i)<<endl;
         ans  = f(i,1);
         cout<<"ans "<<ans<<endl;
         if(ans)
            {
                ans = 1;
                break;
            }
     }
     if(ans)
        cout<<"FOUND"<<endl;
     else
        cout<<"NOT FOUND"<<endl;
}
