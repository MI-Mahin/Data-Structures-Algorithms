#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int N=505;
const int INF=1e9+10;

vector<pair<int,int>>g[N];
vector<int>dist(N,INF);
vector<int>vis(N,0);

void dijkstra(int source)
{

    set<pair<int,int>>st;

    st.insert({0,source});
    dist[source]=0;

    while(st.size()>0)
    {
        auto node=*st.begin();
        int v=node.second;
        int v_dist=node.first;
        st.erase(st.begin());
        if(vis[v]) continue;

        vis[v]=1;
        for(auto child:g[v])
        {
            int child_v=child.first;
            int wt=child.second;

            if(dist[v]+wt <dist[child_v])
            {
                dist[child_v] = dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }

    int u;
    cin>>u;
    dijkstra(u);

    int q;
    cin>>q;
    while(q--)
    {
        int v;
        cin>>v;
        if(dist[v]==INF)
        {
            cout<<"NO PATH\n";
        }
        else
        {
            cout<<dist[v]<<"\n";
        }
    }
}

