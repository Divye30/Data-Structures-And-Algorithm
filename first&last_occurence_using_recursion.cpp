#include<iostream>
using namespace std;
int firstOcc(int *a, int n, int key)
{
    if(n==0)
        return -1;
    if(a[0]==key)
        return 0;
    int i=firstOcc(a+1, n-1, key);
    if(i==-1)
        return -1;
    return i+1;
}
int lastOcc(int *a, int n, int key)
{
    if(n==0)
        return -1;
    int i=lastOcc(a+1,n-1,key);
    if(i==-1)
    {
        if(a[0]==key)
            return 0;
        return -1;
    }
    return i+1;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    int key;
    cin>>key;
    cout<<firstOcc(arr, n, key)<<endl;
    cout<<lastOcc(arr, n, key)<<endl;
    delete [] arr;
    arr=NULL;
}
