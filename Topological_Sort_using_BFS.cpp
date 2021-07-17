#include <iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
using namespace std;
class Graph{
    list<int> *L;
    int V;
public:
    Graph(int V)
    {
        this->V=V;
        L=new list<int>[V];
    }
    void AddEdge(int x,int y)
    {
        L[x].push_back(y);
    }
    void topological_sort()
    {
        int *indegree=new int[V];
        for(int i=0; i<V; i++)
            indegree[i]=0;
        for(int i=0; i<V; i++)
        {
            for(auto Y : L[i])
            {
                indegree[Y]++;
            }
        }
        queue<int> q;
        for(int i=0; i<=V; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr:L[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};
int main()
{
    Graph G(6);
    G.AddEdge(0, 2);
    G.AddEdge(1, 2);
    G.AddEdge(1, 4);
    G.AddEdge(2, 3);
    G.AddEdge(2, 5);
    G.AddEdge(3, 5);
    G.AddEdge(4, 5);
    G.topological_sort();
}
