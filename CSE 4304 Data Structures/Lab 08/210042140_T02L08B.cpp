#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
vector<int> node[maxn];
int cats[maxn],vis[maxn];
int n,mxcat,u,v,ans=0;
void dfs(int x,int st)
{
    if(vis[x]==1) return;
    vis[x]=1;
    if(cats[x]) st++;
    else st=0;
    if(st>mxcat) return;
    if(node[x].size()==1 && x!=1)
    {
        ans++;
        return ;
    }
    for(int i = 0; i<node[x].size(); i++)
    {
        dfs(node[x][i],st);
    }
}
int main()
{
    cin>>n>>mxcat;
    for(int i = 1; i<=n; i++)
    {
        cin>>cats[i];
    }
    for(int i = 1; i<n; i++)

    {
        cin>>u>>v;
        node[u].push back(v);
        node[v].push back(u);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
