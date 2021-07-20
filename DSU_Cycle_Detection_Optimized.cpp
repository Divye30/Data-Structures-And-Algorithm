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
    int find_set_optimized(int i, int parent[])
    {
        if(parent[i]==-1)
            return i;
        return parent[i]=find_set_optimized(parent[i], parent);
    }
    void union_set_optimized(int x,int y,int parent[],int rank[])
    {
        int s1=find_set_optimized(x,parent);
        int s2=find_set_optimized(y, parent);
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    bool contains_cycle()
    {
        int *parent=new int[V];
        int *rank=new int[V];
        for(int i=0; i<V; i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        for(auto edge:L)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=find_set_optimized(i, parent);
            int s2=find_set_optimized(j,parent);
            if(s1!=s2)
                union_set_optimized(s1,s2,parent,rank);
            else
                return true;
        }
        delete [] parent;
        delete [] rank;
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


