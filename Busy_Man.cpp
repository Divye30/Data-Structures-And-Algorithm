#include<iostream>
using namespace std;
typedef pair<int,int> P;
bool cmp(P a,P b)
{
    return a.second<b.second;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        P arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].first>>arr[i].second;
        }
        sort(arr,arr+n,cmp);
        int chosen=0,count=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i].first>=arr[chosen].second)
            {
                chosen=i;
                count++;
            }
        }
        cout<<count<<endl;
    }
}
