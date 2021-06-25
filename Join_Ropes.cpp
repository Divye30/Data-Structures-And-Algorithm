#include<iostream>
#include<queue>
using namespace std;
int joinRopes(int arr[], int n)
{
    priority_queue<int,vector<int>, greater<int>> pq(arr,arr+n);
    int cost=0;
    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        cost+=a+b;
        pq.push(a+b);
    }
    return cost;
}
int main()
{
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<joinRopes(arr, n)<<endl;
}
