#include<iostream>
using namespace std;
int main()
{
    int a[9]={-4,1,3,-2,16,2,-1,-4,-7};
    int temp[9]={a[0]};
    int currentSum=0,maxSum=0;
    int left=-1,right=-1;
    for(int i=1; i<9; i++)
        temp[i]=temp[i-1]+a[i];
    for(int i=0; i<9; i++){
            for(int j=i; j<9; j++)
            {
                currentSum=0;
                currentSum=temp[j]-temp[i-1];
                if(currentSum>maxSum){
                    maxSum=currentSum;
                    left=i;
                    right=j;
                }
            }
        }
    cout<<"The subarray with max sum is"<<endl;
    for(int k=left; k<=right; k++)
    cout<<a[k]<<" ";
    cout<<endl<<maxSum<<endl;
}
