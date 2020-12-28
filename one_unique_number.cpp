#include<iostream>
using namespace std;
void unique_number(int arr[], int n)
{
    int count[64]={0};
    for(int i=0; i<n; i++)
    {
        int j=0;
        while(arr[i]>0)
        {
            int last_bit=arr[i]&1;
            count[j]+=last_bit;
            j++;
            arr[i]=arr[i]>>1;
        }
    }
    int ans=0;
    int p=1;
    for(int k=0; k<64; k++)
    {
        count[k]%=3;
        ans+=count[k]*p;
        p=p<<1;
    }
    cout<<ans<<endl;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    unique_number(arr, n);
    delete [] arr;
    arr=NULL;
}
