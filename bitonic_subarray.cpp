#include<iostream>
using namespace std;
void max_biotonic_subarray(int arr[],int n)
{
    int max_len=0;
    int I[n+1];
    I[0]= 1;
    for(int i=1; i<=n; i++)
    {
        I[i]=1;
        if(arr[i-1]<arr[i])
          I[i]=I[i-1] + 1;
    }
    int D[n+1];
    D[n]= 1;
    for(int i=n-1; i>=0; i--)
    {
        D[i]= 1;
        if(arr[i] > arr[i+1])
          D[i] = D[i+1] + 1;
    }
    max_len= I[0]+D[0]-1;
    for(int i=1; i<=n; i++)
      if(I[i]+D[i]-1>max_len)
        max_len= I[i]+D[i]-1;
    cout<<max_len<<endl;
}
int main()
{
    int n,t;
    cin>>t;
    for(int j=0; j<t; j++)
    {
        cin>>n;
        int *arr= new int[n];
        for(int i=0; i<n; i++)
           cin>>arr[i];
        max_biotonic_subarray(arr,n);
        delete[] arr;
        arr=NULL;
    }
}

