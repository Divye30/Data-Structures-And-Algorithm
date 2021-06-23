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
        map<T,int> visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            cout<<node<<",";
            for(auto Nbr:M[node])
            {
                if(!visited[Nbr])
                {
                    q.push(Nbr);
                    visited[Nbr]=true;
                }
            }
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
    cout<<endl;
}
