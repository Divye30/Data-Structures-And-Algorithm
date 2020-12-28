#include<iostream>
using namespace std;
void uniqueNumbers(int arr[], int n)
{
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans=ans^arr[i];
    }
    int pos=0;
    int temp=ans;
    while((temp&1)==0)
    {
        pos++;
        temp=temp>>1;
    }
    int mask=1<<pos;
    int a=0;
    for(int i=0; i<n; i++)
    {
        if((mask&arr[i])>0)
            a=a^arr[i];
    }
    int b=ans^a;
    cout<<min(a,b)<<" "<<max(a,b)<<endl;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    uniqueNumbers(arr, n);
    delete [] arr;
    arr=NULL;
}
