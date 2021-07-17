#include<iostream>
#include<queue>
#include<cstring>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> M;
public:
    void AddEdge(T x,T y)
    {
        M[x].push_back(y);
    }
    void DFS_helper(T src, map<T,bool>&visited, list<T>&ordering)
    {
        visited[src]=true;
        for(T nbr:M[src])
        {
            if(!visited[nbr])
                DFS_helper(nbr, visited,ordering);
        }
        ordering.push_front(src);
        return;
    }
    void DFS()
    { 
        map<T,bool> visited;
        list<T> ordering;
        for(auto P:M)
        {
            T node=P.first;
            visited[node]=false;
        }
        for(auto P:M)
        {
            T node=P.first;
            if(!visited[node])
                DFS_helper(node, visited,ordering);
        }
        for(auto node:ordering)
        {
            cout<<node<<endl;
        }
    }
};
int main()
{
    Graph<string> G;
    G.AddEdge("Python", "DataPreprocessing");
    G.AddEdge("Python", "Pytorch");
    G.AddEdge("Python", "ML");
    G.AddEdge("DataPreprocessing", "ML");
    G.AddEdge("PyTorch", "DL");
    G.AddEdge("ML", "DL");
    G.AddEdge("DL", "FaceRecognition");
    G.AddEdge("DataSet", "FaceRecognition");
    G.DFS();
}
