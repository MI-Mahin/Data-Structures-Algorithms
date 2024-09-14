#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        vector<int>adj[20008];
        int vis[20008]={0};
        int type[20008]={0};

        set<int>s;

        int n;
        cin>>n;
        while (n--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            s.insert(a);
            s.insert(b);
        }

        ll ans=0;
        //for(auto i:s) cout<<i<<" "; cout<<"\n";

        for(auto i:s)
        {
            //cout<<i<<"\n";
            if(!vis[i])
            {
                queue<int>q;
                q.push(i);
                vis[i]=1;
                type[i]=1;
                int cnt1=1,cnt2=0;
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    for(int v:adj[u])
                    {
                        if(!vis[v])
                        {
                            vis[v]=1;
                            q.push(v);
                            if(type[u]==1) {type[v]=2; cnt2++;}
                            else {type[v]=1; cnt1++;}
                        }
                    }
                }
                ans+=max(cnt1,cnt2);
                //cout<<ans<<"\n";
            }
        }
        cout<<"Case "<<i<<": ";
        cout<<ans<<"\n";

    }
}

