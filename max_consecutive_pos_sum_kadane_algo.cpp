#include<iostream>
using namespace std;
int main()
{
    int currentSum=0, maxSum=0;
    int a[9]={-4,1,3,-2,6,2,-1,-4,-7};
    for(int i=0; i<9; i++)
    {
        currentSum=currentSum+a[i];
        if(currentSum<0)
            currentSum=0;
        maxSum=max(currentSum,maxSum);
    }
    cout<<maxSum<<endl;
}
