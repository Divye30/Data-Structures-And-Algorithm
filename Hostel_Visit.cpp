#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long,pair<long,long>> Pair;
void query_print(priority_queue<long,vector<long>,greater<long>> pq, long k)
{
    while(k>1)
    {
        pq.pop();
        k--;
    }
    cout<<pq.top()<<endl;
}
int main()
{
    long q,k;
    cin>>q>>k;
    Pair p;
    long temp=0;
    priority_queue<long,vector<long>, greater<long>> pq;
    while(q--)
    {
        cin>>p.first;
        if(p.first==2 && temp>=k)
        {
            query_print(pq,k);
        }
        else
        {
            cin>>p.second.first>>p.second.second;
            pq.push(abs(p.second.first*p.second.first) + abs(p.second.second*p.second.second));
            temp++;
        }
    }
}
