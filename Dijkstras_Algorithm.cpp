#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<cstring>
using namespace std;
template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> M;
public:
    void AddEdge(T u,T v,int dist,bool bidir=true)
    {
        M[u].push_back(make_pair(v,dist));
        if(bidir)
            M[v].push_back(make_pair(u,dist));
    }
    void printAdjList()
    {
        for(auto j:M)
        {
            cout<<j.first<<"->";
            for(auto l:j.second)
            {
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }
    }
    void dijkstra(T src)
    {
        unordered_map<T, int> dist;
        for(auto j:M)
        {
            dist[j.first]=INT_MAX;
        }
        set<pair<int,T>> S;
        dist[src]=0;
        S.insert(make_pair(0,src));
        while(!S.empty())
        {
            auto p= *(S.begin());
            T node= p.second;
            int nodeDist=p.first;
            S.erase(S.begin());
            for(auto childPair:M[node])
            {
                if(nodeDist+childPair.second<dist[childPair.first])
                {
                    T dest=childPair.first;
                    auto F=S.find(make_pair(dist[dest],dest));
                    if(F!=S.end())
                    {
                        S.erase(F);
                    }
                    dist[dest]=nodeDist+childPair.second;
                    S.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto D:dist)
        {
            if(D.first!=src)
             cout<<D.first<<" is located at a distance of:"<<D.second<<" from "<<src<<endl;
        }
    }
};
int main()
{
    Graph<string> G;
    //G.AddEdge(source,destination,weight)
    G.AddEdge("Amritsar", "Delhi", 1);
    G.AddEdge("Amritsar", "Jaipur", 4);
    G.AddEdge("Jaipur", "Delhi", 2);
    G.AddEdge("Jaipur", "Mumbai", 8);
    G.AddEdge("Bhopal", "Agra", 2);
    G.AddEdge("Mumbai", "Bhopal", 3);
    G.AddEdge("Agra", "Delhi", 1);
    G.printAdjList();
    G.dijkstra("Amritsar");
}
