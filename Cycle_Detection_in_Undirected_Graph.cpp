#include<iostream>
#include<list>
using namespace std;
class Graph{
    list<int> *l;
    int V;
public:
    Graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }
    void AddEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool Cyclic_Helper(int node, bool *visited, int parent)
    {
        visited[node]=true;
        for(auto nbr:l[node])
        {
            if(!visited[nbr])
            {
                bool temp=Cyclic_Helper(nbr, visited, node);
                if(temp)
                    return true;
            }
            else if(nbr!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCyclic()
    {
        bool *visited=new bool[V]();
        return Cyclic_Helper(0, visited, -1);
    }
};
int main()
{
    Graph G(5);
    G.AddEdge(0, 1);
    G.AddEdge(1, 2);
    G.AddEdge(2, 3);
    G.AddEdge(3, 4);
    G.AddEdge(4, 0);
    if(G.isCyclic())
        cout<<"Graph contains a cycle"<<endl;
    else
        cout<<"Graph does not contain a cycle"<<endl;
}
