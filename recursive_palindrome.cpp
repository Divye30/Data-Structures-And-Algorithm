#include<iostream>
using namespace std;
bool palindrome(int *arr, int start, int end)
{
    while(start<=end)
    {
        if(arr[start]==arr[end])
        {
            return palindrome(arr,start+1,end-1);
        }
        else
            return false;
    }
    return true;
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
    if(palindrome(arr,0,n-1))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    delete [] arr;
    arr=NULL;
}
