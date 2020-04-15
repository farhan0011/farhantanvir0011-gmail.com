#include<bits/stdc++.h>
using namespace std;
#define LIM 12
vector<int>G[LIM];
int vis[LIM];
int n,m;
bool f(int u,int cnt)
{
    if(cnt == n)
        return true;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
       if(vis[v]) continue;
       vis[v] = 1;
       if(f(v,cnt+1))return true;
       vis[v] = 0;
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans  = 0;
    for(int i=1; i<=n; i++)
    {
        memset(vis,0,sizeof vis);
        vis[i] = 1;
        ans = f(i,1);
        if(ans)
        {
            ans = 1;
            break;
        }
        vis[i]=0;
    }
    if(ans)
        cout<<"found"<<endl;
    else
        cout<<"NOT FOUND"<<endl;
}
