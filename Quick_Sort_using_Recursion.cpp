#include<iostream>
using namespace std;
int partion(int *arr, int s, int e)
{
    int i=s-1;
    int j=s;
    int pivot=arr[e];
    for(; j<=e-1; j++)
    {
        if(arr[j]<=pivot)
        {
            i=i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
void quicksort(int *arr, int start, int end)
{
    if(start>=end)
    {
        return;
    }
    int pivot=partion(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    quicksort(arr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
    arr=NULL;
}
