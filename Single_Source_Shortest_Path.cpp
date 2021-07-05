#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> M;
public:
    void AddEdge(T x,T y)
    {
        M[x].push_back(y);
        M[y].push_back(x);
    }
    void BFS(T src)
    {
        map<T,int> dist;
        queue<T> q;
        q.push(src);
        for(auto node_pairs:M)
        {
            T node=node_pairs.first;
            dist[node]=INT_MAX;
        }
        dist[src]=0;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(auto Nbr:M[node])
            {
                if(dist[Nbr]==INT_MAX)
                {
                    q.push(Nbr);
                    dist[Nbr]=dist[node]+1;
                }
            }
        }
        for(auto node_pair:M)
        {
            T node=node_pair.first;
            int d=dist[node];
            cout<<"Node "<<node<<" Distance from Source: "<<d<<endl;
        }
    }
};
int main()
{
    Graph<int> G;
    G.AddEdge(0, 1);
    G.AddEdge(0, 3);
    G.AddEdge(1, 2);
    G.AddEdge(2, 3);
    G.AddEdge(3, 4);
    G.AddEdge(4, 5);
    G.BFS(0);
}

