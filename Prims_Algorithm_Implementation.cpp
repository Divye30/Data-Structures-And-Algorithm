#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    vector<pair<int,int>> *L;
    int V;
public:
    Graph(int n)
    {
        V=n;
        L=new vector<pair<int,int>>[n];
    }
    void AddEdge(int x,int y,int w)
    {
        L[x].push_back({y,w});
        L[y].push_back({x,w});
    }
    int prims_mst(int src)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
        bool *visited=new bool[V]();
        int ans=0;
        Q.push({0,src}); //weight,node
        while(!Q.empty())
        {
            auto best=Q.top();
            Q.pop();
            int dest=best.second;
            int weight=best.first;
            if(visited[dest])
            {
                continue;
            }
            ans+=weight;
            visited[dest]=1;
            for(auto x:L[dest])
            {
                if(!visited[x.first])
                {
                    Q.push({x.second,x.first});
                }
            }
        }
        return ans;
    }
};
int main()
{
    Graph G(4);
    G.AddEdge(0, 1, 1);
    G.AddEdge(1, 2, 2);
    G.AddEdge(2, 3, 3);
    G.AddEdge(2, 0, 2);
    G.AddEdge(0, 3, 2);
    G.AddEdge(1, 3, 3);
    cout<<G.prims_mst(0)<<endl;
}
