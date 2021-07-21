#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class DSU{
    int *parent;
    int *rank;
public:
    DSU(int n)
    {
        parent=new int[n];
        rank=new int[n];
        for(int i=0; i<n; i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find_set(int i)
    {
        if(parent[i]==-1)
            return i;
        return parent[i]=find_set(parent[i]);
    }
    void unite_set(int x,int y)
    {
        int s1=find_set(x);
        int s2=find_set(y);
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};
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
        edgeList.push_back({w,x,y});
    }
    int kruskal_mst()
    {
        sort(edgeList.begin(),edgeList.end());
        DSU S(V);
        int ans=0;
        for(auto edge:edgeList)
        {
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            if(S.find_set(x)!=S.find_set(y))
            {
                S.unite_set(x, y);
                ans+=w;
            }
        }
        return ans;
    }
};
int main()
{
    Graph G(4);
    G.AddEdge(0, 1, 1);
    G.AddEdge(1, 3, 3);
    G.AddEdge(3, 2, 4);
    G.AddEdge(2, 0, 2);
    G.AddEdge(0, 3, 2);
    G.AddEdge(1, 2, 2);
    cout<<G.kruskal_mst()<<endl;
}
