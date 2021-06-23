#include<iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;
class Graph{
    map<string,list<pair<string,int>>> M;
public:
    void AddEdge(string x,string y,bool  BiDir,int Wt)
    {
        M[x].push_back(make_pair(y,Wt));
        if(BiDir)
            M[y].push_back(make_pair(x,Wt));
    }
    void PrintAdjList()
    {
        for(auto P:M)
        {
            string city=P.first;
            list<pair<string,int>> Nbrs=P.second;
            cout<<city<<"->";
            for(auto Nbr: Nbrs)
            {
                cout<<"("<<Nbr.first<<","<<Nbr.second<<")"<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph G;
    G.AddEdge("A", "B", true, 20);
    G.AddEdge("B", "D", true, 30);
    G.AddEdge("A", "C", true, 10);
    G.AddEdge("D", "C", true, 40);
    G.AddEdge("A", "D", false, 50);
    G.PrintAdjList();
}
