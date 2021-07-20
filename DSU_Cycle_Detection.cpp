#include<iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>> L;
public:
    Graph(int V)
    {
        this->V=V;
    }
    void AddEdge(int u,int v)
    {
        L.push_back(make_pair(u,v));
    }
    int find_set(int i, int parent[])
    {
        if(parent[i]==-1)
            return i;
        return find_set(parent[i], parent);
    }
    void union_set(int x,int y,int parent[])
    {
        int s1=find_set(x,parent);
        int s2=find_set(y, parent);
        if(s1!=s2)
            parent[s2]=s1;
    }
    bool contains_cycle()
    {
        int *parent=new int[V];
        for(int i=0; i<V; i++)
            parent[i]=-1;
        for(auto edge:L)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=find_set(i, parent);
            int s2=find_set(j,parent);
            if(s1!=s2)
                union_set(s1,s2,parent);
            else
                return true;
        }
        delete [] parent;
        return false;
    }
};
int main()
{
    Graph G(4);
    G.AddEdge(0, 1);
    G.AddEdge(1, 2);
    G.AddEdge(2, 3);
    G.AddEdge(3, 0);
    if(G.contains_cycle())
        cout<<"Graph has a cycle"<<endl;
    else
        cout<<"Graph does not contain a cycle"<<endl;
}

