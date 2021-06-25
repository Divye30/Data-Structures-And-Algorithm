#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Pair{
public:
    int distance;
    int fuel;
};
bool compare(Pair a, Pair b)
{
    return a.distance<b.distance;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,L,P;
        cin>>n;
        vector<Pair> v;
        for(int i=0; i<n; i++)
        {
            Pair P;
            cin>>P.distance>>P.fuel;
            v.push_back(P);
        }
        cin>>L>>P;
        for(int i=0; i<n; i++)
        {
            v[i].distance=L-v[i].distance;
        }
        sort(v.begin(),v.end(),compare);
        int count=0;
        int i=0;
        int prev=0;
        int flag=0;
        priority_queue<int> pq;
        while(i<n)
        {
            if(P>=v[i].distance-prev)
            {
                P=P-v[i].distance+prev;
                pq.push(v[i].fuel);
                prev=v[i].distance;
            }
            else
            {
                if(pq.empty())
                {
                    flag=1;
                    break;
                }
                P+=pq.top();
                pq.pop();
                count++;
                continue;
            }
            i++;
        }
        if(flag==1)
        {
            cout<<-1<<endl;
            continue;
        }
        L=L-v[n-1].distance;
        if(P>=L)
        {
            cout<<count<<endl;
            continue;
        }
        while(P<L)
        {
            if(pq.empty())
            {
                flag=1;
                break;
            }
            P+=pq.top();
            pq.pop();
            count++;
        }
        if(flag==1)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<count<<endl;
    }
}
