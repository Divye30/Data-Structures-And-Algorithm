#include<iostream>
#include<list>
#include<queue>
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
    void AddEdge(int x,int y,bool directed=true)
    {
        l[x].push_back(y);
        if(!directed)
          l[y].push_back(x);
    }
    bool Cyclic_Helper(int node, bool *visited, bool *stack)
    {
        visited[node]=true;
        stack[node]=true;
        for(int nbr:l[node])
        {
            if(stack[nbr]==true)
                return true;
            else if(visited[nbr]==false)
            {
                bool temp=Cyclic_Helper(nbr, visited, stack);
                if(temp==true)
                    return true;
            }
        }
        stack[node]=false;
        return false;
    }
    bool isCyclic()
    {
        bool *visited=new bool[V]();
        bool *stack=new bool[V]();
        return Cyclic_Helper(0, visited, stack);
    }
};
int main()
{
    Graph G(7);
    G.AddEdge(0, 1);
    G.AddEdge(1, 2);
    G.AddEdge(2, 3);
    G.AddEdge(3, 4);
    G.AddEdge(4, 5);
    G.AddEdge(1, 5);
    G.AddEdge(5, 6);
    G.AddEdge(4, 2);
    if(G.isCyclic())
        cout<<"Graph contains cycle"<<endl;
    else
        cout<<"Graph  does not contain cycle"<<endl;
}
