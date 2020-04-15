#include<bits/stdc++.h>
using namespace std;
#define LIM 12
vector<int>G[LIM];
int colour[LIM];
int n,m,col;
/// f : u -> u node k colour korbo
bool f(int u)
{
    if(u>n)
        return true;
   ///first e check korte hobe u er stahe connected node gulate ki ki colour ase
   bool used[10] = {0};
   for(int i=0;i<G[u].size();i++)
   {
       int v = G[u][i];
       if(!colour[v] )continue;
        used[colour[v]] = true;
   }
   for(int i=1; i<=col; i++)
   {
       if(used[i]) continue;
        colour[u] = i;
       if(f(u+1))
        return true;
       colour[u] = 0;
   }
   return false;
}
int main()
{
   cin>>n>>m>>col;
   for(int i=0; i<m; i++)
   {
       int u,v;
       cin>>u>>v;
       G[u].push_back(v);
       G[v].push_back(u);
   }
   int ans = f(1);
   cout<<ans<<endl;
   if(ans)
   {
       for(int u=1; u<=n; u++)
        cout<<u<<" "<<colour[u]<<endl;
   }
}
/**
8 14 3
1 2
1 3
1 4
2 4
2 6
2 8
3 5
3 8
4 6
4 7
5 7
5 8
6 7
7 8
*/
