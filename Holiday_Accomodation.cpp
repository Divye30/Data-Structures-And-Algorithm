#include<iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>>*L;
public:
    Graph(int v)
    {
        V=v;
        L=new list<pair<int,int>>[v];
    }
    void AddEdge(int u,int v,int cost)
    {
        L[u].push_back(make_pair(v,cost));
        L[v].push_back(make_pair(u,cost));
    }
    int dfsHelper(int node, bool *visited, int *count, int &ans)
    {
        visited[node]=true;
        count[node]=1;
        for(auto nbr_pair:L[node])
        {
            int nbr=nbr_pair.first;
            if(!visited[nbr])
            {
                count[node]+=dfsHelper(nbr, visited, count, ans);
                int nx=count[nbr];
                int ny=V-nx;
                ans+=2*min(nx,ny)*nbr_pair.second;
            }
        }
        return count[node];
    }
    int dfs()
    {
        bool *visited=new bool[V]();
        int *count=new int[V]();
        int ans=0;
        dfsHelper(0,visited,count,ans);
        return ans;
    }
};
int main()
{
    Graph G(4);
    G.AddEdge(0, 1, 3);
    G.AddEdge(1, 2, 2);
    G.AddEdge(2, 3, 2);
    cout<<G.dfs()<<endl;
}
