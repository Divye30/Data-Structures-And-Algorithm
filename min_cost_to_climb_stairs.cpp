#include<iostream>
#include<vector>
using namespace std;
int min_cost(vector<int> cost)
{
    for(int i=cost.size()-3; ~i; i--)
        cost[i]+=min(cost[i+1], cost[i+2]);
    return min(cost[0], cost[1]);
}
int main()
{
    int n;
    cin>>n;
    vector<int> cost;
    for(int i=0; i<n; i++)
    {
        int data;
        cin>>data;
        cost.push_back(data);
    }
    cout<<min_cost(cost)<<endl;
}
