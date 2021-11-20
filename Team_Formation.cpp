#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long teamFormation(vector<int> score, int team, int m)
{
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    int n=score.size();
    int i;
    for(i=0; i<m; i++)
    {
        pq1.push(score[i]);
        score[i]=-1;
        pq2.push(score[n-i-1]);
        score[n-i-1]=-1;
    }
    int var=0;
    long count=0;
    int j=i;
    while(var<team)
    {
        if((pq2.empty() and !pq1.empty()) or pq1.top()>=pq2.top())
        {
            count+=pq1.top();
            pq1.pop();
            if(score[i]>=0)
            {
               pq1.push(score[i]);
               score[i]=-1;
                i++;
            }
            var++;
        }
        else if((pq1.empty() and !pq2.empty()) or pq2.top()>pq1.top())
        {
            count+=pq2.top();
            pq2.pop();
            if(score[n-j-1]>=0)
            {
                pq2.push(score[n-j-1]);
                score[n-j-1]=-1;
                j++;
            }
            var++;
        }
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int> score;
    for(int i=0; i<n; i++)
    {
        int data;
        cin>>data;
        score.push_back(data);
    }
    int team,m;
    cin>>team>>m;
    cout<<teamFormation(score,team,m)<<endl;
}
