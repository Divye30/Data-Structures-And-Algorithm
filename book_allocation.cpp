#include<iostream>
#include<algorithm>
using namespace std;
int sum(int arr[], int n)
{
    int s=0;
    for(int i=0; i<n; i++)
    s+=arr[i];
    return s;
}
bool isPossible(int arr[], int n, int m, int min)
{
    int studentUsed=1;
    int pagesReading=0;
    for(int i=0; i<n; i++)
    {
        if(pagesReading+arr[i]>min)
        {
            studentUsed++;
            pagesReading=arr[i];
            if(studentUsed>m)
                return false;
        }
        else
            pagesReading+=arr[i];
    }
    return true;
}
int bin_search(int arr[], int n, int m)
{
    int i=arr[n-1], j=sum(arr,n);
    int ans=100000;
    while(i<=j){
        int mid=(i+j)/2;
        if(isPossible(arr, n, m, mid))
        {
            ans=min(ans,mid);
            j=mid-1;
        }
        else
            i=mid+1;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n,m;
        cin>>n>>m;
        int arr[1000];
        for(int j=0; j<n; j++)
            cin>>arr[j];
        cout<<bin_search(arr, n, m)<<endl;
    }
}
