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
    int pairing()
    {
        int *parent=new int[V];
        int *rank=new int[V];
        for(int i=0; i<V; i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        int ans=0;
        for(auto edge:L)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=find_set_optimized(i, parent);
            int s2=find_set_optimized(j, parent);
            union_set_optimized(s1, s2, parent, rank);
        }
        for(int i=0; i<V; i++)
        {
            ans+=V-rank[find_set_optimized(i, parent)];
        }
        delete [] parent;
        delete [] rank;
        return ans/2;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    Graph G(n);
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        G.AddEdge(u, v);
    }
    cout<<G.pairing()<<endl;
}
