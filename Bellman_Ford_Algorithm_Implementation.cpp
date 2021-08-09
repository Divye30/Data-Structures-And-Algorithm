#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;
class Graph{
    vector<vector<int>> edgeList;
    int V;
public:
    Graph(int V)
    {
        this->V=V;
    }
    void AddEdge(int x,int y, int w)
    {
        edgeList.push_back({x,y,w});
    }
    vector<int> bellmanFord(int src)
    {
        vector<int> dist(V+1,INT_MAX);
        dist[src]=0;
        for(int i=0; i<V-1; i++)
        {
            for(auto edge: edgeList)
            {
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
                    dist[v]=dist[u]+wt;
            }
        }
        for(auto edge:edgeList)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
            {
                cout<<"Negative weight cycle detected."<<endl;
                exit(0);
            }
        }
        return dist;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    Graph G(n);
    for(int i=0; i<m; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        G.AddEdge(x, y, w);
    }
    int src;
    cin>>src;
    auto ans=G.bellmanFord(src);
    for(int i=1; i<=n; i++)
    {
        cout<<"Vertex "<<i<<" is at distance: "<<ans[i]<<" from source vertex: "<<src<<endl;
    }
}
