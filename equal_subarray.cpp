#include<iostream>
#include<algorithm>
using namespace std;
void max_length(int *arr, int n)
{
    int number_of_zeros=0, number_of_ones=0;
    for(int k=0; k<n; k++)
    {
        if(arr[k]==0)
            number_of_zeros+=1;
        else
            number_of_ones+=1;
    }
    //sort(arr,arr+n);
    while(number_of_ones!=number_of_zeros)
    {
        if(number_of_ones>number_of_zeros)
        {
            number_of_ones--;
        }
        else if(number_of_ones<number_of_zeros)
        {
            number_of_zeros--;
        }
    }
    cout<<"Max Length of the subarray with equal number of zeros and ones="<<number_of_ones+number_of_zeros<<endl;
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
    max_length(arr,n);
    delete [] arr;
    arr=NULL;
}
